#pragma once
#include "GameObject.h"
#include "CoinPhysicsObject.h"

/**
 * @class	CoinGameObject
 *
 * @brief	A coin game object which inherits GameObject
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CoinGameObject : public GameObject
{
public:

	/**
	 * @fn	CoinGameObject::CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	 *
	 * @brief	Constructor for the coin game object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	s	If non-null, object shader used when creating the render object
	 * @param	position 	The position in space given to the physical object
	 * @param	mass	 	The mass of the coin
	 * @param	radius   	The radius of the coin
	 * @param	t		 	The Texture given to the render object
	 */

	CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~CoinGameObject();

	/**
	 * @fn	void CoinGameObject::removeFromGame();
	 *
	 * @brief	Removes the coin from the game by setting the
	 * 			physical object to non colliding and deleteing
	 * 			the render object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void removeFromGame();

	/**
	 * @fn	virtual void CoinGameObject::handleCollision(GameObject& obj);
	 *
	 * @brief	Handles the collision described by obj.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	obj	The object.
	 */

	virtual void handleCollision(GameObject& obj);

	/**
	 * @fn	virtual void CoinGameObject::handleCollision(PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between coin and player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */

	virtual void handleCollision(PlayerGameObject& player);

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}

};

