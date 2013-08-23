//
//  MyContactListener.cpp
//  modev
//
//  Created by Alex Swan on 8/17/13.
//
//

#include "MyContactListener.h"
#include "cocos2d.h"

USING_NS_CC;

void MyContactListener::EndContact(b2Contact* contact)
{
//    b2Fixture* a = contact->GetFixtureA();
//    b2Fixture* b = contact->GetFixtureB();
    CCLOG("Contact ended");
    // If one of them is the ground, delete the other
    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    std::vector<MyContact>::iterator pos;
    pos = std::find(_contacts.begin(), _contacts.end(), myContact);
    if (pos != _contacts.end()) {
        _contacts.erase(pos);
    }
    
    
    
//        MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
//        std::vector<MyContact>::iterator pos;
//        pos = std::find(_contacts.begin(), _contacts.end(), myContact);
//        if (pos != _contacts.end())
//            {
//                    _contacts.erase(pos);
//                }
}

void MyContactListener::BeginContact(b2Contact* contact)
{
    // We need to copy out the data because the b2Contact passed in
    // is reused.
//    b2Fixture* a = contact->GetFixtureA();
//    b2Fixture* b = contact->GetFixtureB();
    CCLOG("Contact begun");
    
    
    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    _contacts.push_back(myContact);

//
//     myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
//    _contacts.push_back(myContact);
}

void MyContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){
    
};

void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){
    
}