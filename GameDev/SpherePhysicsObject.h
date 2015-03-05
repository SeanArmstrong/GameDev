#pragma once
#include "PhysicsObject.h"

/**
 * @class	SpherePhysicsObject
 *
 * @brief	A sphere physics object inherits physics object
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class SpherePhysicsObject : public PhysicsObject
{
public:

	/**
	 * @fn	SpherePhysicsObject::SpherePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	 *
	 * @brief	Constructor for sphere physics object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param	pos						The position.
	 * @param	mass					The mass.
	 * @param	radius					The radius.
	 */

	SpherePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~SpherePhysicsObject();

	/**
	 * @fn	virtual void SpherePhysicsObject::updateRenderObject();
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void updateRenderObject();

protected:

	float radius;
};

