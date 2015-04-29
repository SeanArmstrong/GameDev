#pragma once
#include "PlatformPhysicsObject.h"
#include "GameTimer.h"

class MovingPlatformPhysicsObject : public PlatformPhysicsObject
{
public:
	MovingPlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass,
		const float width, const float height, const float depth, const Vector3& direction, 
		const float distance, const float speed);
	~MovingPlatformPhysicsObject();

	virtual void updateRenderObject();
private:

	Vector3 direction;
	float distance;
	float distanceTravelled;
	float speed;
};
