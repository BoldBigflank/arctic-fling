//
//  HelloWorldScene.h
//  modev
//
//  Created by Alex Swan on 8/17/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"
#include "MyContactListener.h"

USING_NS_CC;

class PhysicsSprite : public cocos2d::CCSprite
{
public:
    PhysicsSprite();
    void setPhysicsBody(b2Body * body);
    virtual bool isDirty(void);
    virtual cocos2d::CCAffineTransform nodeToParentTransform(void);
private:
    b2Body* m_pBody;    // strong ref
};

class HelloWorld : public cocos2d::CCLayer {
public:
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    
    void initPhysics();
    void newGame();
    // adds a new sprite at a given coordinate
    b2Body * addNewSpriteAtPosition(string name, cocos2d::CCPoint p, CCPoint velocity);

    virtual void draw();
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent *event);
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent* event);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    void update(float dt);
    
private:
    bool gameInProgress;
    b2World* world;
    b2Body* groundBody;
    b2Fixture *bottomFixture;
    b2Body* base1;
    b2Body* base2;
    CCLabelTTF *label;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
    MyContactListener *contactListener;
};

#endif // __HELLO_WORLD_H__
