#pragma once
#include "SpherePhysicsObject.h"
#include "GameTimer.h"

class PerimeterEnemyPhysicsObject : public SpherePhysicsObject
{
public:
	PerimeterEnemyPhysicsObject(RenderObject* renderObject, const Vector3& startPos, const float radius,
		const float xDistance, const float zDistance, const float speed, const Vector3& startDirection);
	virtual ~PerimeterEnemyPhysicsObject();

	virtual void updateRenderObject();
private:

	float xDistance;
	float zDistance;
	float speed;
	Vector3 direction;
	float distanceTravelled;

};

