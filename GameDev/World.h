#pragma once
#include "btBulletDynamicsCommon.h"
#include <iostream>
#include "GameObject.h"
#include "PlayerGameObject.h"

/**
 * @class	World
 *
 * @brief	The physical world of the game
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class World
{
public:
	World();
	~World();

	/**
	 * @fn	btDefaultCollisionConfiguration* World::getCollisionConfiguration() const;
	 *
	 * @brief	Gets collision configuration.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the collision configuration.
	 */

	btDefaultCollisionConfiguration* getCollisionConfiguration() const;

	/**
	 * @fn	btCollisionDispatcher* World::getDispatcher() const;
	 *
	 * @brief	Gets the dispatcher.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the dispatcher.
	 */

	btCollisionDispatcher* getDispatcher() const;

	/**
	 * @fn	btBroadphaseInterface* World::getBroadPhase() const;
	 *
	 * @brief	Gets broad phase.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the broad phase.
	 */

	btBroadphaseInterface* getBroadPhase() const;

	/**
	 * @fn	btSequentialImpulseConstraintSolver* World::getSolver() const;
	 *
	 * @brief	Gets the solver.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the solver.
	 */

	btSequentialImpulseConstraintSolver* getSolver() const;

	/**
	 * @fn	btDiscreteDynamicsWorld* World::getPhysicsWorld() const;
	 *
	 * @brief	Gets physics world.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the physics world.
	 */

	btDiscreteDynamicsWorld* getPhysicsWorld() const;

	/**
	 * @fn	void World::callbackChecker(PlayerGameObject* player, std::vector<GameObject*> eventObjects);
	 *
	 * @brief	Callback checker used to check if a player collides
	 * 			with any other game object that we are intrested in
	 * 			
	 * 			TODO: GHOST OBJECTS TO IMPROVE EFFIENCY
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player			If non-null, the player.
	 * @param [in,out]	eventObjects	If non-null, the event objects.
	 */

	void callbackChecker(PlayerGameObject* player, std::vector<GameObject*> eventObjects);

	/**
	 * @fn	void World::addPhysicsObject(btRigidBody* body);
	 *
	 * @brief	Adds a body to the physical world.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	body	If non-null, the body.
	 */

	void addPhysicsObject(btRigidBody* body);

private:

	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* broadPhase;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* physicsWorld;


	// World could also include a renderer
};

