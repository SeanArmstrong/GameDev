#pragma once
#include "btBulletDynamicsCommon.h"
#include <iostream>
#include "GameObject.h"
#include "PlayerGameObject.h"

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
	
	void callbackChecker(PlayerGameObject* player, std::vector<GameObject*> eventObjects);

	void addPhysicsObject(btRigidBody* body);

private:

	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* broadPhase;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* physicsWorld;


	// World could also include a renderer
};

