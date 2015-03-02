#pragma once
#include "PhysicsObject.h"

class PlanePhysicsObject : public PhysicsObject
{
public:
	PlanePhysicsObject(RenderObject* renderObject, Vector3& pos, const float mass, const float distance);
	virtual ~PlanePhysicsObject();

	virtual void updateRenderObject();
};

