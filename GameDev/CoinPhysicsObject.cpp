#include "CoinPhysicsObject.h"


CoinPhysicsObject::CoinPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius) : PhysicsObject(renderObject, pos, mass)
{
	this->radius = radius;
	shape = new btSphereShape(radius);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(pos.x, pos.y, pos.z));

	btDefaultMotionState* motionState = new btDefaultMotionState(startTransform);
	btVector3 fallInertia(0, 0, 0);
	shape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, motionState, shape, fallInertia);
	body = new btRigidBody(fallRigidBodyCI);

	// Does not have collision response
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
}


CoinPhysicsObject::~CoinPhysicsObject()
{
}

void CoinPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	Matrix4 rotation = ro->GetModelMatrix();
	rotation.SetPositionVector(Vector3(0, 0, 0));
	rotation = rotation * Matrix4::Rotation(1.0f, Vector3(0, 1, 0));

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * rotation * Matrix4::Scale(Vector3(radius, radius, radius)));

}