#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"
#include "CollisionResponse.h"

/**
* @class	EndGameGameObject
*
* @brief	EndGameGameObject inherits from Game Object
*			Signifies the end of a level - a goal to reach
*			TODO - Inherit from platform
*
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class EndGameGameObject : public GameObject
{
public:

	/**
	* @fn	EndGameGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, GLuint t = 0, const bool hasRenderObject = false);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s				If non-null, object shader used when creating the render object
	* @param	position 				The position in space given to the physical object
	* @param	mass	 				The mass of the object
	* @param	lengthHeightDepth   	Dimensions
	* @param	t		 				The Texture given to the render object
	* @param	hasRenderObject			Sets if it has a graphical representation
	*/
	EndGameGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, GLuint t = 0, const bool hasRenderObject = false);
	virtual ~EndGameGameObject();

	/**
	* @fn	virtual void handleCollision(GameObject& obj);
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
	* @fn	virtual void handleCollision(PlayerGameObject& player);
	*
	* @brief	Handles the collision between end game and player.
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

