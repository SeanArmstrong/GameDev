#pragma once
#include "PhysicsObject.h"

/**
 * @class	CubePhysicsObject
 *
 * @brief	A cube physics object inherits physics object
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CubePhysicsObject : public PhysicsObject
{
public:

	/**
	 * @fn	CubePhysicsObject::CubePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float length);
	 *
	 * @brief	Constructor for cube physics object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param	pos						The position.
	 * @param	mass					The mass.
	 * @param	length					The length.
	 */

	CubePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float length);
	~CubePhysicsObject();

	/**
	 * @fn	virtual void CubePhysicsObject::updateRenderObject();
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void updateRenderObject();

protected:

	float length;

};

