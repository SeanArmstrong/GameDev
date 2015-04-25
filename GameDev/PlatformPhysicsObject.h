#pragma once
#include "PhysicsObject.h"
class PlatformPhysicsObject : public PhysicsObject {
public:
	// TODO Change widht height depth to vector3 
	PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass,
							const float width, const float height, const float depth);
	virtual ~PlatformPhysicsObject();

	virtual void updateRenderObject();

protected:

	float width;
	float height;
	float depth;
};

