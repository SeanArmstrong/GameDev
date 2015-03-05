#pragma once
#include "SpherePhysicsObject.h"

class CoinPhysicsObject : public SpherePhysicsObject
{
public:
	CoinPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~CoinPhysicsObject();

	virtual void updateRenderObject();

private:
};

