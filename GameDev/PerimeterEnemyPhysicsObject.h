#pragma once
#include "SpherePhysicsObject.h"
#include "GameTimer.h"


/**
* @class	PerimeterEnemyPhysicsObject
*
* @brief	A platform physics object inherits physics object
*			dimensions from length height depth vector
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PerimeterEnemyPhysicsObject : public SpherePhysicsObject
{
public:

	/**
	* @fn	PerimeterEnemyPhysicsObject(RenderObject* renderObject, const Vector3& startPos, const float radius,
		const float xDistance, const float zDistance, const float speed, const Vector3& startDirection);
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	startPosition			The position.
	* @param	radius					radius of the sphere (TODO make generic mesh)
	* @param	xDistance			    distance to travel in x direction
	* @param	zDistance				distance to travel in z direction
	* @param	speed					speed of movement
	* @param	startDirection			Vector of direction the object first moves in
	*/
	PerimeterEnemyPhysicsObject(RenderObject* renderObject, const Vector3& startPos, const float radius,
		const float xDistance, const float zDistance, const float speed, const Vector3& startDirection);
	virtual ~PerimeterEnemyPhysicsObject();

	/**
	* @fn	virtual void PerimeterEnemyPhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void updateRenderObject();
private:

	float xDistance;
	float zDistance;
	float speed;
	Vector3 direction;
	float distanceTravelled;

};

