#include "PlanePhysicsObject.h"


PlanePhysicsObject::PlanePhysicsObject(RenderObject* renderObject, Vector3& normal, const float mass, const float distance) : PhysicsObject(renderObject, normal, mass){
	// gives normal and ditance
	normal.Normalise();
	shape = new btStaticPlaneShape(btVector3(normal.x, normal.y, normal.z), distance);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 0, 0));

	btDefaultMotionState* groundMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo groundRigidBody(mass, groundMotionState, shape, btVector3(0, 0, 0));
	body = new btRigidBody(groundRigidBody);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
}


PlanePhysicsObject::~PlanePhysicsObject()
{
}

void PlanePhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix());
}
