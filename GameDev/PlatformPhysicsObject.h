#pragma once
#include "PhysicsObject.h"
class PlatformPhysicsObject : public PhysicsObject {
public:
	PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, bool canCollide = true);
	virtual ~PlatformPhysicsObject();

	virtual void updateRenderObject();

protected:

	Vector3 lengthHeightDepth;
};

