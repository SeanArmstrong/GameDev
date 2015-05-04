#pragma once
#include "GameObject.h"
#include "CubePhysicsObject.h"

/**
 * @class	CubeGameObject
 *
 * @brief	A cube game object which inherits GameObject
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CubeGameObject : public GameObject
{
public:

	/**
	 * @fn	CubeGameObject::CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t = 0);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	s	If non-null, object shader used when creating the render object
	 * @param	position 	The position in space given to the physical object
	 * @param	mass	 	The mass of the coin
	 * @param	length   	The length of a side
	 * @param	t		 	The Texture given to the render object
	 */

	CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t = 0);
	virtual ~CubeGameObject();

	/**
	 * @fn	virtual void CubeGameObject::handleCollision(GameObject& obj);
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
	 * @fn	virtual void CubeGameObject::handleCollision(PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between a cube and a player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */

	virtual void handleCollision(PlayerGameObject& player){}

	/**
	 * @fn	virtual void CubeGameObject::handleCollision(PlaneGameObject& plane);
	 *
	 * @brief	Handles the collision between a cube and a plane.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane	The plane.
	 */

	virtual void handleCollision(PlaneGameObject& plane){}

	/**
	 * @fn	virtual void CubeGameObject::handleCollision(CoinGameObject& coin);
	 *
	 * @brief	Handles the collision between a cube and a coin.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin	The coin.
	 */

	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}

};

