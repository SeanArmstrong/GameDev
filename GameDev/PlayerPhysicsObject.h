#pragma once
#include "SpherePhysicsObject.h"
#include "RenderObject.h"

class PlayerPhysicsObject : public SpherePhysicsObject
{
public:
	PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~PlayerPhysicsObject();

	void PlayerPhysicsObject::updateRenderObject();

private:

	float deceleration;
	float maxSpeed;
	float jumpImpulse;
	float jumpRechargeTime;

};

