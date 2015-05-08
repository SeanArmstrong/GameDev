#pragma once
#include "SpherePhysicsObject.h"

/**
* @class	PoolBallPhysicsObject
*
* @brief	A pool ball physics object inherits physics object
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PoolBallPhysicsObject : public SpherePhysicsObject
{
public:

	/**
	* @fn	PoolBallPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	pos						The position.
	* @param	mass					The mass.
	* @param	radius					The radius of the ball
	*/
	PoolBallPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~PoolBallPhysicsObject();

	/**
	* @fn	virtual void PoolBallPhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void updateRenderObject();
};

