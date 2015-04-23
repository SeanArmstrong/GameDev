#pragma once
#include <vector>
#include "RenderObject.h"
#include "PhysicsObject.h"
#include "SFMLRenderer.h"
#include "btBulletDynamicsCommon.h"
#include "ResourceManager.h"
#include "GameTimer.h"

class World;
class PlayerGameObject;
class PlaneGameObject;
class CoinGameObject;
class PoolBallGameObject;

/**
 * @class	GameObject
 *
 * @brief	Abstract class for all game objects
 * 			
 * 			Game objects hold the physical and graphical
 * 			representation of objects in the game.
 * 			It doesn't have to have both a physical and
 * 			a graphical representation
 * 			Such as a invisible plane or a hud display
 * 			
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class GameObject
{
public:
	GameObject(){};
	virtual ~GameObject();

	/**
	 * @fn	void GameObject::addPhysicsObjectToWorld(btDynamicsWorld& world);
	 *
	 * @brief	Adds the physics object to world.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	world	The world.
	 */

	void addPhysicsObjectToWorld(btDynamicsWorld& world);

	/**
	 * @fn	void GameObject::addRenderObjectToWorld(SFMLRenderer& renderer);
	 *
	 * @brief	Adds a render object to world.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderer	The renderer.
	 */

	void addRenderObjectToWorld(SFMLRenderer& renderer);

	/**
	 * @fn	void GameObject::removePhysicsObjectFromWorld(btDynamicsWorld& world);
	 *
	 * @brief	Removes the physics object from world described by world.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	world	The world.
	 */

	void removePhysicsObjectFromWorld(btDynamicsWorld& world);

	/**
	 * @fn	void GameObject::removeRenderObjectFromWorld(SFMLRenderer& renderer);
	 *
	 * @brief	Removes the render object from world described by renderer.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderer	The renderer.
	 */

	void removeRenderObjectFromWorld(SFMLRenderer& renderer);

	/**
	 * @fn	RenderObject* GameObject::getRenderObject();
	 *
	 * @brief	Gets render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it does not exist, else the render object.
	 */

	RenderObject* getRenderObject();

	/**
	 * @fn	PhysicsObject* GameObject::getPhysicsObject();
	 *
	 * @brief	Gets physics object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it does not exist, else the physics object.
	 */

	PhysicsObject* getPhysicsObject();

	/**
	 * @fn	bool GameObject::getExistsInWorld();
	 *
	 * @brief	Returns if the object still exists in the world
	 * 			This is set to false when it is destroyed by a 
	 * 			collision or other means so that the update function 
	 * 			can remove it.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	bool getExistsInWorld();

	/**
	 * @fn	void GameObject::setExistsInWorld(bool status);
	 *
	 * @brief	Sets if the object exists in the world to the status
	 * 			Usually true by default and is set to false after collision
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	status	true to status.
	 */

	void setExistsInWorld(bool status);

	/**
	 * @fn	virtual void GameObject::update();
	 *
	 * @brief	Updates this object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void update();

	/**
	 * @fn	virtual void GameObject::handleCollision(GameObject& obj) = 0;
	 *
	 * @brief	Handles the collision described by obj.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	obj	The object.
	 */

	virtual void handleCollision(GameObject& obj) = 0;

	/**
	 * @fn	virtual void GameObject::handleCollision(PlayerGameObject& player)= 0;
	 *
	 * @brief	Handles the collision with a player.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */

	virtual void handleCollision(PlayerGameObject& player)= 0;

	/**
	 * @fn	virtual void GameObject::handleCollision(PlaneGameObject& plane) = 0;
	 *
	 * @brief	Handles the collision with a plane.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane	The plane.
	 */

	virtual void handleCollision(PlaneGameObject& plane) = 0;

	/**
	 * @fn	virtual void GameObject::handleCollision(CoinGameObject& coin) = 0;
	 *
	 * @brief	Handles the collision with a coin.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin	The coin.
	 */

	virtual void handleCollision(CoinGameObject& coin) = 0;
	virtual void handleCollision(PoolBallGameObject& poolball) = 0;

protected:
	RenderObject* ro;
	PhysicsObject* po;

	bool existsInWorld = true;
	//GameObject* parent;
	//std::vector<GameObject> children;

};

