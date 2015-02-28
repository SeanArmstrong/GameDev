#include "World.h"


World::World(){
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new	btCollisionDispatcher(collisionConfiguration);
	broadPhase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	physicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfiguration);
	physicsWorld->setGravity(btVector3(0, -9.81f, 0));
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