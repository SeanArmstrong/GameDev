#pragma once
#include "SpherePhysicsObject.h"
class PoolBallPhysicsObject : public SpherePhysicsObject
{
public:
	PoolBallPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~PoolBallPhysicsObject();

	void updateRenderObject();
};

