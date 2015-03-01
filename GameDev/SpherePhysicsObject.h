#pragma once
#include "PhysicsObject.h"

class SpherePhysicsObject : public PhysicsObject
{
public:
	SpherePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~SpherePhysicsObject();

	virtual void PhysicsObject::updateRenderObject();

private:

	float radius;
};

