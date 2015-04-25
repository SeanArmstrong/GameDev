#include "MovingPlatformPhysicsObject.h"


MovingPlatformPhysicsObject::MovingPlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass,
	const float width, const float height, const float depth, const Vector3& direction, const float distance, const float speed) 
		: PlatformPhysicsObject(renderObject, pos, mass, width, height, depth){

	this->direction = direction;
	this->distance = distance;
	this->speed = speed;

	body->setLinearVelocity(btVector3(direction.x, direction.y, direction.z));
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	body->setActivationState(DISABLE_DEACTIVATION);
}


MovingPlatformPhysicsObject::~MovingPlatformPhysicsObject()
{
}

void MovingPlatformPhysicsObject::updateRenderObject(){
	float d = (speed * GameTimer::getDelta());

	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	trans.setOrigin(trans.getOrigin() + btVector3(direction.x * d, direction.y * d, direction.z * d));
	body->setWorldTransform(trans);
	body->getMotionState()->setWorldTransform(trans);

	distanceTravelled += d;
	if (distanceTravelled > distance){
		distanceTravelled = 0;
		direction = Vector3(-direction.x, -direction.y, -direction.z);
	}

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(width, height, depth)));
}
