#pragma once
#include "PhysicsObject.h"

/**
 * @class	PlanePhysicsObject
 *
 * @brief	A plane physics object inherits physics objects
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class PlanePhysicsObject : public PhysicsObject
{
public:

	/**
	 * @fn	PlanePhysicsObject::PlanePhysicsObject(RenderObject* renderObject, Vector3& pos, const float mass, const float distance);
	 *
	 * @brief	Constructor for plane physics object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param [in,out]	pos				The position.
	 * @param	mass					The mass.
	 * @param	distance				The distance.
	 */

	PlanePhysicsObject(RenderObject* renderObject, Vector3& pos, const float mass, const float distance);
	virtual ~PlanePhysicsObject();

	/**
	 * @fn	virtual void PlanePhysicsObject::updateRenderObject();
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void updateRenderObject();

private:

	float distance;
	Vector3 normal;
};

