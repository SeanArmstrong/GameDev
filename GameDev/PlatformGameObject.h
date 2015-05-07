#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"

/**
* @class	MovingPlatformGameObject
*
* @brief	Platform game object inherits from GameObject
*			Defined by vector of dimensions lengthHeightDepth
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PlatformGameObject : public GameObject
{
public:

	/**
	* @fn	PlatformGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, GLuint t = 0);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s				If non-null, object shader used when creating the render object
	* @param	position 				The position in space given to the physical object
	* @param	mass	 				The mass of the object
	* @param	lengthHeightDepth		Dimensions of platform
	* @param	t		 				The Texture given to the render object
	*/
	PlatformGameObject(Shader*s, const Vector3& position, const float mass,
			const Vector3& lengthHeightDepth, GLuint t = 0);
	virtual ~PlatformGameObject();

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

