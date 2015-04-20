#include "PlatformPhysicsObject.h"


PlatformPhysicsObject::PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float width, const float height, const float depth) : 
				PhysicsObject(renderObject, pos, mass) {
	this->width = width;
	this->height = height;
	this->depth = depth;
	shape = new btBoxShape(btVector3(width, height, depth));

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(pos.x, pos.y, pos.z));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btVector3 fallInertia(0, 0, 0);
	shape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, shape, fallInertia);
	body = new btRigidBody(fallRigidBodyCI);
	body->setRestitution(0.5f);
	body->setFriction(1.0f);
}


PlatformPhysicsObject::~PlatformPhysicsObject(){

}

void PlatformPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(width, height, depth)));
}
