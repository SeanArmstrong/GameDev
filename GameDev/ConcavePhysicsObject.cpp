#include "ConcavePhysicsObject.h"


ConcavePhysicsObject::ConcavePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale) 
					: PhysicsObject(renderObject, pos, mass){
	this->scale = scale;
	this->mesh = m;

	btTriangleMesh tetraMesh;

	Vector3* verts = m->getVertices();
	for (int i = 0; i < m->getNumberOfVertices(); i++){
		tetraMesh.addTriangle(btVector3(verts[i].x * scale, verts[i].y * scale, verts[i].z * scale),
							btVector3(verts[i+1].x * scale, verts[i+1].y * scale, verts[i+1].z * scale),
							btVector3(verts[i+2].x * scale, verts[i+2].y * scale, verts[i+2].z * scale));
	}


	shape = new btBvhTriangleMeshShape(&tetraMesh, false);

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(pos.x, pos.y, pos.z));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btVector3 fallInertia(0, 0, 0);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, shape, fallInertia);
	
	body = new btRigidBody(fallRigidBodyCI);
	body->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);


}


ConcavePhysicsObject::~ConcavePhysicsObject()
{
}

void ConcavePhysicsObject::updateRenderObject(){
	//btTransform trans;
	//body->getMotionState()->getWorldTransform(trans);

	//ro->SetModelMatrix(trans);
	//ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(scale, scale, scale)));
}