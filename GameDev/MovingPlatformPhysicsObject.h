#pragma once
#include "PlatformPhysicsObject.h"
#include "GameTimer.h"

class MovingPlatformPhysicsObject : public PlatformPhysicsObject
{
public:

	/**
	* @fn		MovingPlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, 
		const Vector3& direction, const float distance, const float speed);
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	pos						The position the object starts and pivots over
	* @param	mass					mass of object
	* @param	direction				direction of initial travel
	* @param	distance				distance to travel in direction
	* @param	speed					speed of movement
	*/
	MovingPlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, 
		const Vector3& direction, const float distance, const float speed);
	~MovingPlatformPhysicsObject();

	/**
	* @fn	virtual void MovingPlatformPhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void updateRenderObject();
private:

	Vector3 direction;
	float distance;
	float distanceTravelled;
	float speed;
};

