#include "PlayerPhysicsObject.h"



PlayerPhysicsObject::PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius) : PhysicsObject(renderObject, pos, mass)
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
	
	body->setRestitution(0.8f);
	body->setFriction(1.0f);
	body->setActivationState(DISABLE_DEACTIVATION); // always active
	body->setAngularFactor(0.0f); // Keep upright
	body->setCollisionFlags(btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	
}


PlayerPhysicsObject::~PlayerPhysicsObject()
{
}

void PlayerPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	Vector3 pos = Vector3(trans.getOrigin().x(), trans.getOrigin().y(), trans.getOrigin().z());

	ro->SetModelMatrix(Matrix4::Translation(pos)* Matrix4::Scale(Vector3(radius, radius, radius)));

}
