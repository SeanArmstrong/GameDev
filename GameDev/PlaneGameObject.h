#pragma once
#include "GameObject.h"
#include "PlanePhysicsObject.h"
#include "PlaneGameObject.h"
#include "CollisionResponse.h"

class PlaneGameObject :public GameObject
{
public:
	enum PlayerContactAction { Nothing, Deadly, Reset, Checkpoint };

	/**
	 * @fn	PlaneGameObject::PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	normal	The normal that defines the plane
	 * @param	mass		  	The mass. Set to 0 so plane doesn't move
	 * @param	distance	  	The distance down the normal
	 * @param [in,out]	s	  	If non-null, object shader used when creating the render object
	 * @param	t			  	Plane Texture for render object
	 * @param PlayerContact Action	Action to take on collision with player
	 */
	PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	virtual ~PlaneGameObject();

	/**
	 * @fn	bool PlaneGameObject::isDeadly();
	 *
	 * @brief	Query if this object is deadly to the player character
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	true if deadly, false if not.
	 */
	bool isDeadly();

	/**
	 * @fn	virtual void PlaneGameObject::handleCollision(GameObject& obj);
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
	 * @fn	virtual void PlaneGameObject::handleCollision(PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between a plane and a player.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */
	virtual void handleCollision(PlayerGameObject& player);

	/**
	 * @fn	virtual void PlaneGameObject::handleCollision(PlaneGameObject& plane);
	 *
	 * @brief	Handles the collision between a plane and a plane.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane	The plane.
	 */
	virtual void handleCollision(PlaneGameObject& plane){}

	/**
	 * @fn	virtual void PlaneGameObject::handleCollision(CoinGameObject& coin);
	 *
	 * @brief	Handles the collision between a plane and a coin.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin	The coin.
	 */
	virtual void handleCollision(CoinGameObject& coin){}

	/**
	* @fn	virtual void handleCollision(PoolBallGameObject& poolball);
	*
	* @brief	Handles the collision between a plane and a poolball.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	poolball	The poolball.
	*/
	virtual void handleCollision(PoolBallGameObject& poolball);

	/**
	* @fn	virtual void handleCollision(CheckpointGameObject& checkpoint);
	*
	* @brief	Handles the collision between a plane and a checkpoint.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	checkpoint	The checkpoint.
	*/
	virtual void handleCollision(CheckpointGameObject& checkpoint){}

	/**
	* @fn	virtual void handleCollision(EndGameGameObject& endGame);
	*
	* @brief	Handles the collision between a plane and a endGame.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	endGame	The endGame.
	*/
	virtual void handleCollision(EndGameGameObject& endGame){}


	/**
	* @fn	inline PlayerContactAction getPlayerAction(){ return playerAction; }
	*
	* @brief	Returns the action to take upon collision
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @return PlaneGameObject::PlayerContactAction ( enum PlayerContactAction { Nothing, Deadly, Reset, Checkpoint } )
	*/
	inline PlayerContactAction getPlayerAction(){ return playerAction; }

private:

	//Action to take when colliding
	PlayerContactAction playerAction;
};

