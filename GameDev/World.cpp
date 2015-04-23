#include "World.h"
#include "BulletDebugDraw.h"


World::World(){
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new	btCollisionDispatcher(collisionConfiguration);
	broadPhase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	physicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfiguration);
	physicsWorld->setGravity(btVector3(0, -9.81f, 0));
	//BulletDebugDraw* drawer = new BulletDebugDraw();
	//drawer->DBG_DrawWireframe;
	//drawer->setDebugMode(drawer->getDebugMode() | btIDebugDraw::DBG_DrawWireframe);
	//physicsWorld->setDebugDrawer(drawer);
}

// can remove player
void World::callbackChecker(PlayerGameObject* player, std::vector<GameObject*> eventObjects){
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

				bool aIsEventObject = false;
				bool bIsEventObject = false;

				for (std::vector<GameObject*>::iterator i = eventObjects.begin(); i != eventObjects.end(); ++i) {
					if (obA->getUserPointer() == (*i)){
						aIsEventObject = true;
					}
					if (obB->getUserPointer() == (*i)){
						bIsEventObject = true;
					}
				}

				if (aIsEventObject && bIsEventObject){
					// This will break if event object cannot be handled
					GameObject* a = static_cast<GameObject*>(obA->getUserPointer());
					GameObject* b = static_cast<GameObject*>(obB->getUserPointer());
					a->handleCollision(*b);
				}
			}
		}
	}
}

World::~World()
{
	delete collisionConfiguration;
	delete dispatcher;
	delete broadPhase;
	delete solver;
	delete physicsWorld;
}

void World::addPhysicsObject(btRigidBody* body){
	physicsWorld->addRigidBody(body);
}

// Getters

btDefaultCollisionConfiguration* World::getCollisionConfiguration() const{
	return collisionConfiguration;
}

btCollisionDispatcher*  World::getDispatcher() const{
	return dispatcher;
}

btBroadphaseInterface*  World::getBroadPhase() const{
	return broadPhase;
}

btSequentialImpulseConstraintSolver*  World::getSolver() const{
	return solver;
}

btDiscreteDynamicsWorld*  World::getPhysicsWorld() const{
	return physicsWorld;
}