#pragma once
#include "PhysicsObject.h"

/**
* @class	ConvexPhysicsObject
*
* @brief	Convex Physics Object allows for any convex shape to have a 
* 			physics representation. It adds each vertex from the given mesh
* 			to calculate its physical presence
*
* @author	Sean Armstrong
* @date	22/04/2015
*/
class ConvexPhysicsObject : public PhysicsObject
{
public:

	/**
	* @fn	ConvexPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	pos						The position.
	* @param	mass					The mass.
	* @param	mesh				    Mesh the contains vertices for object
	* @param	scale					Scale of object
	*/
	ConvexPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	~ConvexPhysicsObject();

	/**
	* @fn	virtual void ConvexPhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void updateRenderObject();

private:
	float scale;
	Mesh* mesh;
};

