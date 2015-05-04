#include "PerimeterEnemyPhysicsObject.h"


PerimeterEnemyPhysicsObject::PerimeterEnemyPhysicsObject(RenderObject* renderObject, const Vector3& startPos, const float radius,
	const float xDistance, const float zDistance, const float speed, const Vector3& startDirection) : SpherePhysicsObject(renderObject, startPos, 0, radius)
{
	this->xDistance = xDistance;
	this->zDistance = zDistance;
	this->speed = speed;
	this->direction = startDirection;
	direction.unitVector();

	body->setLinearVelocity(btVector3(direction.x, direction.y, direction.z));
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	body->setActivationState(DISABLE_DEACTIVATION);
}


PerimeterEnemyPhysicsObject::~PerimeterEnemyPhysicsObject()
{
}

void PerimeterEnemyPhysicsObject::updateRenderObject(){
	float d = (speed * GameTimer::getDelta());

	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	if (direction == Vector3(1, 0, 0)){
		trans.setOrigin(trans.getOrigin() + btVector3(direction.x * d, direction.y * d, direction.z * d));
		body->setWorldTransform(trans);
		body->getMotionState()->setWorldTransform(trans);

		distanceTravelled += d;
		if (distanceTravelled > xDistance){
			distanceTravelled = 0;
			direction = Vector3(0, 0, -1);
		}
	}
	else if (direction == Vector3(0, 0, -1)){
		trans.setOrigin(trans.getOrigin() + btVector3(direction.x * d, direction.y * d, direction.z * d));
		body->setWorldTransform(trans);
		body->getMotionState()->setWorldTransform(trans);

		distanceTravelled += d;
		if (distanceTravelled > zDistance){
			distanceTravelled = 0;
			direction = Vector3(-1, 0, 0);
		}
	}
	else if (direction == Vector3(-1, 0, 0)){
		trans.setOrigin(trans.getOrigin() + btVector3(direction.x * d, direction.y * d, direction.z * d));
		body->setWorldTransform(trans);
		body->getMotionState()->setWorldTransform(trans);

		distanceTravelled += d;
		if (distanceTravelled > xDistance){
			distanceTravelled = 0;
			direction = Vector3(0, 0, 1);
		}
	}
	else{ // direction == Vector3(0, 0, 1)
		trans.setOrigin(trans.getOrigin() + btVector3(direction.x * d, direction.y * d, direction.z * d));
		body->setWorldTransform(trans);
		body->getMotionState()->setWorldTransform(trans);

		distanceTravelled += d;
		if (distanceTravelled > zDistance){
			distanceTravelled = 0;
			direction = Vector3(1, 0, 0);
		}
	}

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(radius, radius, radius)));
}

