#pragma once
#include "GameObject.h"
#include "SpherePhysicsObject.h"

/**
 * @class	SphereGameObject
 *
 * @brief	A sphere game object which inherits GameObject
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */
class SphereGameObject : public GameObject
{
public:

	/**
	 * @fn	SphereGameObject::SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	s	If non-null, object shader used when creating the render object
	 * @param	position 	The position in space given to the physical object
	 * @param	mass	 	The mass of the coin
	 * @param	radius   	The length of a side
	 * @param	t		 	The Texture given to the render object
	 */
	SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~SphereGameObject();

	/**
	 * @fn	virtual void SphereGameObject::handleCollision(GameObject& obj);
	 *
	 * @brief	Handles the collision described by obj.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	obj	The object.
	 */
	virtual void handleCollision(GameObject& obj){}

	/**
	 * @fn	virtual void SphereGameObject::handleCollision(PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between a sphere and a player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */
	virtual void handleCollision(PlayerGameObject& player){}

	/**
	 * @fn	virtual void SphereGameObject::handleCollision(PlaneGameObject& plane);
	 *
	 * @brief	Handles the collision between a sphere and a plane.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane	The plane.
	 */
	virtual void handleCollision(PlaneGameObject& plane){}

	/**
	 * @fn	virtual void SphereGameObject::handleCollision(CoinGameObject& coin);
	 *
	 * @brief	Handles the collision between a sphere and a coin.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin	The coin.
	 */
	virtual void handleCollision(CoinGameObject& coin){}

	/**
	* @fn	virtual void handleCollision(PoolBallGameObject& poolball)
	*
	* @brief	Handles the collision between a sphere and a poolball.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	poolball	The poolball.
	*/
	virtual void handleCollision(PoolBallGameObject& poolball){}

	/**
	* @fn	virtual void handleCollision(CheckpointGameObject& checkpoint)
	*
	* @brief	Handles the collision between a sphere and a checkpoint.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	checkpoint	The checkpoint.
	*/
	virtual void handleCollision(CheckpointGameObject& checkpoint){}


	/**
	* @fn	virtual void handleCollision(EndGameGameObject& endGame)
	*
	* @brief	Handles the collision between a sphere and a endGame.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	endGame	The endGame.
	*/
	virtual void handleCollision(EndGameGameObject& endGame){}
};

