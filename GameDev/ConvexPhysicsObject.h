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
	ConvexPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	~ConvexPhysicsObject();

	void updateRenderObject();

private:
	float scale;
	Mesh* mesh;
};

