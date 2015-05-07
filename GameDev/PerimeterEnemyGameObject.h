#pragma once
#include "GameObject.h"
#include "PerimeterEnemyPhysicsObject.h"


/**
* @class	MovingPlatformGameObject
*
* @brief	PerimeterEnemyGameObject moves in a quad permiters (Currently X and Z)
*			Travelling from a start position in a start direction
*			once the distance in the given direction (x or z) has been travelled
*			the object will change to move in other axis direction
*			eventually completing a quad shape
*
*			TODO - Mesh as params
*			TODO - Extend Direction
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PerimeterEnemyGameObject : public GameObject
{
public:

	/**
	* @fn	PerimeterEnemyGameObject(Shader*s, const Vector3& startPosition, const Vector3& startDirection, const float radius,
		const float xDistance, const float zDistance, const float speed, GLuint t = 0);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s		If non-null, object shader used when creating the render object
	* @param	startPosition 	The position in space given to the physical object
	* @param	startDirection	Direction of initial travel ( x or z)
	* @param	radius   		radius of sphere (extend mesh todo)
	* @param	xDistance		distance to travel in x direction
	* @param	zDistance		distance to travel in z direction
	* @param	speed			speed of travel
	* @param	t		 		The Texture given to the render object
	*/
	PerimeterEnemyGameObject(Shader*s, const Vector3& startPosition, const Vector3& startDirection, const float radius,
		const float xDistance, const float zDistance, const float speed, GLuint t = 0);
	virtual ~PerimeterEnemyGameObject();

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

