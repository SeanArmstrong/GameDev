#pragma once
#include "btBulletDynamicsCommon.h"
#include <iostream>

class World
{
public:
	World();
	~World();

	// Getters
	btDefaultCollisionConfiguration* getCollisionConfiguration() const;
	btCollisionDispatcher* getDispatcher() const;
	btBroadphaseInterface* getBroadPhase() const;
	btSequentialImpulseConstraintSolver* getSolver() const;
	btDiscreteDynamicsWorld* getPhysicsWorld() const;
	
	int callbackChecker(){
		int numManifolds = physicsWorld->getDispatcher()->getNumManifolds();
		for (int i = 0; i < numManifolds; i++){
			btPersistentManifold* contactManifold = physicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
			const btCollisionObject* obA = contactManifold->getBody0();
			const btCollisionObject* obB = contactManifold->getBody1();

			int numContacts = contactManifold->getNumContacts();
			for (int j = 0; j < numContacts; j++)
			{
				btManifoldPoint& pt = contactManifold->getContactPoint(j);
				if (pt.getDistance() < 0.f)
				{
					const btVector3& ptA = pt.getPositionWorldOnA();
					const btVector3& ptB = pt.getPositionWorldOnB();
					const btVector3& normalOnB = pt.m_normalWorldOnB;
					if (obA->getUserIndex() == 1 && obB->getUserIndex() == 2 || 
						obB->getUserIndex() == 1 && obA->getUserIndex() == 1){
						std::cout << "Collision with plane. End game" << std::endl;
						return 9;
					}
				}
			}
		}
		return 0;
	}

	void addPhysicsObject(btRigidBody* body);

private:

	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* broadPhase;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* physicsWorld;


	// World could also include a renderer
};

