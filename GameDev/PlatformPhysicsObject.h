#pragma once
#include "PhysicsObject.h"

/**
* @class	PlatformPhysicsObject
*
* @brief	A platform physics object inherits physics object
*			dimensions from length height depth vector
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PlatformPhysicsObject : public PhysicsObject {
public:

	/**
	* @fn	PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, bool canCollide = true);
	*
	* @brief	Constructor 
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	pos						The position.
	* @param	mass					The mass.
	* @param	lengthHeightDepth	    Dimensions
	* @param	canCollide				Sets contact response to null if false
	*/
	PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, bool canCollide = true);
	virtual ~PlatformPhysicsObject();

	/**
	* @fn	virtual void PlatformPhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void updateRenderObject();

protected:

	Vector3 lengthHeightDepth;
};

