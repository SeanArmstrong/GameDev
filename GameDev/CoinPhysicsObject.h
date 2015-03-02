#pragma once
#include "PhysicsObject.h"

class CoinPhysicsObject : public PhysicsObject
{
public:
	CoinPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~CoinPhysicsObject();

	virtual void updateRenderObject();

private:

	float radius;
};

