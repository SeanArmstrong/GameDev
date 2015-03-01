#pragma once
#include "PhysicsObject.h"
#include "RenderObject.h"

class PlayerPhysicsObject : public PhysicsObject
{
public:
	PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~PlayerPhysicsObject();

	void PlayerPhysicsObject::updateRenderObject();

private:

	float radius;

	float deceleration;
	float maxSpeed;
	float jumpImpulse;
	float jumpRechargeTime;

};

