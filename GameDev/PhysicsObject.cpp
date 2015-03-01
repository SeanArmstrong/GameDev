#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass){
	this->ro = renderObject;
	this->position = pos;
	this->mass = mass;
}


PhysicsObject::~PhysicsObject()
{
}

btRigidBody* PhysicsObject::getBody() const{
	return body;
}
