//
//  HelloWorldScene.cpp
//  modev
//
//  Created by Alex Swan on 8/17/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GB2ShapeCache-x.h"
#include "MyContactListener.h"

using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32
#define BASE_MAX_TORQUE 30
#define MAX_ANGLE (M_PI / 3.0)

enum {
    kTagParentNode = 1,
};

PhysicsSprite::PhysicsSprite()
: m_pBody(NULL)
{

}

void PhysicsSprite::setPhysicsBody(b2Body * body)
{
    m_pBody = body;
}

// this method will only get called if the sprite is batched.
// return YES if the physics values (angles, position ) changed
// If you return NO, then nodeToParentTransform won't be called.
bool PhysicsSprite::isDirty(void)
{
    return true;
}

// returns the transform matrix according the Chipmunk Body values
CCAffineTransform PhysicsSprite::nodeToParentTransform(void)
{
    b2Vec2 pos  = m_pBody->GetPosition();

    float x = pos.x * PTM_RATIO;
    float y = pos.y * PTM_RATIO;

    if ( isIgnoreAnchorPointForPosition() ) {
        x += m_obAnchorPointInPoints.x;
        y += m_obAnchorPointInPoints.y;
    }

    // Make matrix
    float radians = m_pBody->GetAngle();
    float c = cosf(radians);
    float s = sinf(radians);

    if( ! m_obAnchorPointInPoints.equals(CCPointZero) ){
        x += c*-m_obAnchorPointInPoints.x + -s*-m_obAnchorPointInPoints.y;
        y += s*-m_obAnchorPointInPoints.x + c*-m_obAnchorPointInPoints.y;
    }

    // Rot, Translate Matrix
    m_sTransform = CCAffineTransformMake( c,  s,
        -s,    c,
        x,    y );

    return m_sTransform;
}

HelloWorld::HelloWorld()
{
    
    GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
    sc->addShapesWithFile("shapes.plist");
    
    
    setTouchEnabled( true );
    setAccelerometerEnabled( true );

    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCSprite *stage = new CCSprite();
    stage->initWithFile("stage.png");
    stage->setPosition(ccp(s.width/2.0, s.height/2.0));
    addChild(stage);
    
    
    // init physics
    this->initPhysics();

//    CCSpriteBatchNode *parent = CCSpriteBatchNode::create("blocks.png", 100);
//    m_pSpriteTexture = parent->getTexture();
//
//    addChild(parent, 0, kTagParentNode);

    // Base 1
    base1 = addNewSpriteAtPosition("fullModel", ccp(s.width/4.0, s.height/2), CCPointZero);
    CCSprite * base1Sprite = (CCSprite*)base1->GetUserData();
    base1Sprite->setTag(1);
    
    
    // -Friction
    b2FrictionJointDef base1Friction;
    base1Friction.Initialize(base1, groundBody, base1->GetWorldCenter());
    base1Friction.maxTorque = BASE_MAX_TORQUE;
    base1Friction.collideConnected = true;
    world->CreateJoint(&base1Friction);
    
    // -Pivot
    b2RevoluteJointDef base1JointDef;
    base1JointDef.Initialize(base1, groundBody, base1->GetWorldCenter());
    world->CreateJoint(&base1JointDef);
    
    // Base 2
    base2 = addNewSpriteAtPosition("fullModel-right", ccp(3.0*s.width/4.0, s.height/2), CCPointZero);
    CCSprite * base2Sprite = (CCSprite*)base2->GetUserData();
    base2Sprite->setTag(2);
    
    // -Friction
    b2FrictionJointDef base2Friction;
    base2Friction.Initialize(base2, groundBody, base2->GetWorldCenter());
    base2Friction.maxTorque = BASE_MAX_TORQUE;
    base2Friction.collideConnected = true;
    world->CreateJoint(&base2Friction);

    // -Pivot
    b2RevoluteJointDef base2JointDef;
    base2JointDef.Initialize(base2, groundBody, base2->GetWorldCenter());
    world->CreateJoint(&base2JointDef);
    
    label = CCLabelTTF::create("Tap screen", "Marker Felt", 32);
    addChild(label, 0);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( s.width/2, s.height-50));
    
    addNewSpriteAtPosition("icicleRight-sml", ccp(s.width/2, s.height/3), CCPointZero);
    addNewSpriteAtPosition("icicleRight-med", ccp(s.width/2, 2.0* s.height/3), CCPointZero);
    addNewSpriteAtPosition("icicleRight-sml", ccp(s.width/2, s.height/2), CCPointZero);
    
    
    // Start a new game (put a button here)
    gameInProgress = true;
    
    contactListener = new MyContactListener();
    world->SetContactListener(contactListener);
    
    
    
    
    scheduleUpdate();
}

HelloWorld::~HelloWorld()
{
    delete world;
    delete contactListener;
    world = NULL;
    
    //delete m_debugDraw;
}

void HelloWorld::newGame(){
    // Reset the bases, delete the blasts
    base1->SetTransform(base1->GetPosition(), 0);
    base2->SetTransform(base1->GetPosition(), 0);
    
    gameInProgress = true;
}

void HelloWorld::initPhysics()
{

    CCSize s = CCDirector::sharedDirector()->getWinSize();

    b2Vec2 gravity;
    gravity.Set(0.0f, -4.0f);
    world = new b2World(gravity);

    // Do we want to let bodies sleep?
    world->SetAllowSleeping(true);

    world->SetContinuousPhysics(true);

//     m_debugDraw = new GLESDebugDraw( PTM_RATIO );
//     world->SetDebugDraw(m_debugDraw);

    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    //        flags += b2Draw::e_jointBit;
    //        flags += b2Draw::e_aabbBit;
    //        flags += b2Draw::e_pairBit;
    //        flags += b2Draw::e_centerOfMassBit;
    //m_debugDraw->SetFlags(flags);


    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); // bottom-left corner

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2EdgeShape groundBox;

    // bottom

    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
    bottomFixture = groundBody->CreateFixture(&groundBox,0);


    // top
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);

    // left
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);

    // right
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
}

void HelloWorld::draw()
{
    //
    // IMPORTANT:
    // This is only for debug purposes
    // It is recommend to disable it
    //
    CCLayer::draw();

    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );

    kmGLPushMatrix();

    world->DrawDebugData();

    kmGLPopMatrix();
}

b2Body* HelloWorld::addNewSpriteAtPosition(string name, CCPoint p, CCPoint velocity)
{
    CCLOG("Add sprite %0.2f x %02.f",p.x,p.y);

    CCSprite *sprite = CCSprite::create((name+".png").c_str());
    
    sprite->setPosition(p);
    
    addChild(sprite);
    
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
    bodyDef.angle = ccpToAngle(velocity);
	bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody(&bodyDef);
    
    // add the fixture definitions to the body
    
    GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(body, name.c_str());
    sprite->setAnchorPoint(sc->anchorPointForShape(name.c_str()));
    
    
    b2Vec2 f = 6.0 * b2Vec2(velocity.x, velocity.y);
    body->ApplyForceToCenter(f);
    
    return body;
}


void HelloWorld::update(float dt)
{
    //It is recommended that a fixed time step is used with Box2D for stability
    //of the simulation, however, we are using a variable time step here.
    //You need to make an informed choice, the following URL is useful
    //http://gafferongames.com/game-physics/fix-your-timestep/
    
    int velocityIterations = 8;
    int positionIterations = 1;
    
    // Instruct the world to perform a single step of simulation. It is
    // generally best to keep the time step and iterations fixed.
    world->Step(dt, velocityIterations, positionIterations);
    
//    CCLOG("Base rotation %0.2f %0.2f",base1->GetAngle(), base2->GetAngle());
    
    //Iterate over the bodies in the physics world
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            //Synchronize the AtlasSprites position and rotation with the corresponding body
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
        }    
    }
    
    //check contacts
    std::vector<b2Body *>toDestroy;
    std::vector<MyContact>::iterator pos;
    for(pos = contactListener->_contacts.begin();
        pos != contactListener->_contacts.end(); ++pos) {
        MyContact contact = *pos;
        
        b2Body *bodyA = contact.fixtureA->GetBody();
        b2Body *bodyB = contact.fixtureB->GetBody();
        
        if (contact.fixtureA == bottomFixture ) {
            if (std::find(toDestroy.begin(), toDestroy.end(), bodyB) == toDestroy.end()) {
                toDestroy.push_back(bodyB);
            }
        }
        if (contact.fixtureB == bottomFixture){
            if (std::find(toDestroy.begin(), toDestroy.end(), bodyA) == toDestroy.end()) {
                toDestroy.push_back(bodyA);
            }
        }
        
        if (bodyA->GetUserData() != NULL && bodyB->GetUserData() != NULL) {
            CCSprite *spriteA = (CCSprite *) bodyA->GetUserData();
            CCSprite *spriteB = (CCSprite *) bodyB->GetUserData();
            
            //Sprite A = left blast, Sprite B = left base
            if (spriteA->getTag() == 1 && spriteB->getTag() == 3) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyB) == toDestroy.end()) {
                    toDestroy.push_back(bodyB);
                }
            }
            
            else if (spriteA->getTag() == 3 && spriteB->getTag() == 1) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyA) == toDestroy.end()) {
                    toDestroy.push_back(bodyA);
                }
            }
            //Sprite A = right blast, Sprite B = right base
            if (spriteA->getTag() == 2 && spriteB->getTag() == 4) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyB) == toDestroy.end()) {
                    toDestroy.push_back(bodyB);
                }
            }
            
            else if (spriteA->getTag() == 4 && spriteB->getTag() == 2) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyA) == toDestroy.end()) {
                    toDestroy.push_back(bodyA);
                }
            }
        }
    }
    
    std::vector<b2Body *>::iterator pos2;
    for (pos2 = toDestroy.begin(); pos2 != toDestroy.end(); ++pos2) {
        b2Body *body = *pos2;
        if (body->GetUserData() != NULL) {
            CCSprite *sprite = (CCSprite *) body->GetUserData();
            removeChild(sprite);
        }
        world->DestroyBody(body);
    }
    
    if(gameInProgress){
        // Check for game winning conditions
        if( base1->GetAngle() > MAX_ANGLE || base1->GetAngle() < -1.0 * MAX_ANGLE ){
            // Base 2 wins
            label->setString("Player 2 Wins");
            // Unhook penguin 1 from the base
            
            // Show new game button
            gameInProgress = false;
            
        };
        
        if(base2->GetAngle() > MAX_ANGLE || base2->GetAngle() < -1.0 * MAX_ANGLE){
            // Base 2 wins
            label->setString("Player 1 Wins");
            // Unhook penguin 2 from the base
            
            // Show new game button
            gameInProgress = false;
        };

    }
    
}

bool HelloWorld::ccTouchBegan(CCTouch *touch, CCEvent* event){
    return true;
}

void HelloWorld::ccTouchMoved(CCTouch* touch, CCEvent *event){
    
}

string names[] = {
    "fishPink",
    "fishPurple",
    "fishBlue",
    "fishYellow",
    "fishOrange",
    "fishRed",
    "fishGreen"
};

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    if(!gameInProgress) return; // Ignore input when game is ended
    
    //Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        CCPoint location = touch->getLocationInView();
        CCPoint startLocation = touch->getStartLocationInView();
        
        CCPoint velocity = ccpSub(touch->getLocationInView(), touch->getStartLocationInView());
        velocity = CCPointMake(velocity.x, -1.0* velocity.y);
        startLocation = CCDirector::sharedDirector()->convertToGL(startLocation);
        location = CCDirector::sharedDirector()->convertToGL(location);
        
        CCSize s = CCDirector::sharedDirector()->getWinSize();

        string spriteName = names[rand()%7];
        
        b2Body * blast = addNewSpriteAtPosition( spriteName, location, velocity );
        blast->SetAngularVelocity( (rand() % 6) - 3);
        CCSprite * blastSprite = (CCSprite *)blast->GetUserData();
        // Left side 3, right side 4
        blastSprite->setTag(( startLocation.x < s.width/2 ) ? 3:4);
    }
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new HelloWorld();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
