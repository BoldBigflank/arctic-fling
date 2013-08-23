//
//  MyContactListener.h
//  modev
//
//  Created by Alex Swan on 8/17/13.
//
//

#ifndef __modev__MyContactListener__
#define __modev__MyContactListener__

#include <iostream>
#include "Box2D.h"
#include "cocos2d.h"

struct MyContact {
    b2Fixture *fixtureA;
    b2Fixture *fixtureB;
    bool operator==(const MyContact& other) const
    {
        return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
    }
};

class MyContactListener : public b2ContactListener{
    
    private:
        virtual void EndContact(b2Contact* contact);
        
        virtual void BeginContact(b2Contact* contact);
        
        virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
        virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);


    public:
        std::vector<MyContact>_contacts;
};
#endif /* defined(__modev__MyContactListener__) */
