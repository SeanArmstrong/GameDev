#include "SpherePhysicsObject.h"


SpherePhysicsObject::SpherePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius) : PhysicsObject(renderObject, pos, mass)
{
	this->radius = radius;
	shape = new btSphereShape(radius);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(pos.x, pos.y, pos.z));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btVector3 fallInertia(0, 0, 0);
	shape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, shape, fallInertia);
	body = new btRigidBody(fallRigidBodyCI);
}

SpherePhysicsObject::~SpherePhysicsObject()
{
}

void SpherePhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(radius, radius, radius)));
}