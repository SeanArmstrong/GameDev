#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass){
	this->ro = renderObject;
	this->position = pos;
	this->mass = mass < 0 ? 0 : mass;
}


PhysicsObject::~PhysicsObject()
{
}

btRigidBody* PhysicsObject::getBody() const{
	return body;
}

bool PhysicsObject::hasRenderObject(){
	if (ro != NULL){
		return true;
	}
	return false;
}
