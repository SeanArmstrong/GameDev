#include "PoolBallPhysicsObject.h"

PoolBallPhysicsObject::PoolBallPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius)
		: SpherePhysicsObject(renderObject, pos, mass, radius){
	body->setRestitution(0.5f);
	body->setDamping(0.1f, 0.5f);
}


PoolBallPhysicsObject::~PoolBallPhysicsObject(){
}

void PoolBallPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);

	Matrix4 rotation = ro->GetModelMatrix();
	rotation.SetPositionVector(Vector3(0, 0, 0));
	rotation = rotation * Matrix4::Rotation(1.0f, Vector3(0, 1, 0));

	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * rotation * Matrix4::Scale(Vector3(radius, radius, radius)));
}
