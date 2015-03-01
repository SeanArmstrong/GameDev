#include "CubePhysicsObject.h"


CubePhysicsObject::CubePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float length) : PhysicsObject(renderObject, pos, mass)
{
	this->length = length;
	shape = new btBoxShape(btVector3(length, length, length));

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


CubePhysicsObject::~CubePhysicsObject()
{
}

void CubePhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	Vector3 pos = Vector3(trans.getOrigin().x(), trans.getOrigin().y(), trans.getOrigin().z());

	ro->SetModelMatrix(Matrix4::Translation(pos) * Matrix4::Scale(Vector3(length, length, length)));

}
