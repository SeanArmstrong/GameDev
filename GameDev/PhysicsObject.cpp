#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(RenderObject* renderObject, const Vector3& pos){
	this->ro = renderObject;
	this->position = pos;

	btCollisionShape* fallShape = new btSphereShape(1);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 0, -10));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btScalar mass = 1;
	btVector3 fallInertia(0, 0, 0);
	fallShape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
	body = new btRigidBody(fallRigidBodyCI);
}


PhysicsObject::~PhysicsObject()
{
}

btRigidBody* PhysicsObject::getBody(){
	return body;
}

void PhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	Vector3 pos = Vector3(trans.getOrigin().x(), trans.getOrigin().y(), trans.getOrigin().z());
	std::cout << pos;

	ro->SetModelMatrix(Matrix4::Translation(pos));

}
