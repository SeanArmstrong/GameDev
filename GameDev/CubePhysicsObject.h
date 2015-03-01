#pragma once
#include "PhysicsObject.h"

class CubePhysicsObject : public PhysicsObject
{
public:
	CubePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float length);
	~CubePhysicsObject();

	virtual void updateRenderObject();

private:

	float length;

};

