#pragma once
#include "GameObject.h"
#include "MovingPlatformPhysicsObject.h"

/**
* @class	MovingPlatformGameObject
*
* @brief	Moving platform game object moves in the given 
*			direction by the given distance at the given
*			speed. Once the distance has been travelled the platform
*			reverses and continues to pivot around its given position			
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class MovingPlatformGameObject : public GameObject
{
public:

	/**
	* @fn	MovingPlatformGameObject(Shader*s, const Vector3& position, const float mass,
	*			const Vector3& lengthHeightDepth, const Vector3& direction,
	*			const float distance, const float speed, GLuint t = 0);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s			If non-null, object shader used when creating the render object
	* @param	position 			The position in space given to the physical object
	* @param	mass	 			The mass of the object
	* @param	lengthHeightDepth   Dimensions of platform
	* @param	direction		    Direction of travel
	* @param	distance		    Distance travels from origin
	* @param	speed			    speed of travel
	* @param	t		 			The Texture given to the render object
	*/
	MovingPlatformGameObject(Shader*s, const Vector3& position, const float mass,
		const Vector3& lengthHeightDepth, const Vector3& direction,
		const float distance, const float speed, GLuint t = 0);

	virtual ~MovingPlatformGameObject();

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

