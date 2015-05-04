#include "PlatformPhysicsObject.h"


PlatformPhysicsObject::PlatformPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const Vector3& lengthHeightDepth, bool canCollide) :
				PhysicsObject(renderObject, pos, mass) {
	this->lengthHeightDepth = lengthHeightDepth;
	shape = new btBoxShape(btVector3(lengthHeightDepth.x, lengthHeightDepth.y, lengthHeightDepth.z));

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(pos.x, pos.y, pos.z));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btVector3 fallInertia(0, 0, 0);
	shape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, shape, fallInertia);
	body = new btRigidBody(fallRigidBodyCI);
	if (canCollide){
		body->setRestitution(0.5f);
		body->setFriction(1.0f);
	}
	else{
		body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
	}
}


PlatformPhysicsObject::~PlatformPhysicsObject(){

}

void PlatformPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(lengthHeightDepth));
}
