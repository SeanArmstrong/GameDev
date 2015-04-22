#include "ConvexPhysicsObject.h"


ConvexPhysicsObject::ConvexPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale)
					: PhysicsObject(renderObject, pos, mass){
	
	this->scale = scale;
	this->mesh = m;
	btConvexHullShape* s = new btConvexHullShape;
	
	Vector3* verts = m->getVertices();
	for (int i = 0; i < m->getNumberOfVertices(); i++){
		s->addPoint(btVector3(verts[i].x * scale, verts[i].y * scale , verts[i].z * scale));
	}

	shape = s;

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


ConvexPhysicsObject::~ConvexPhysicsObject()
{
}

void ConvexPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(scale,scale,scale)));
}