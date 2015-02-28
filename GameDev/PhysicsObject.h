#pragma once
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "RenderObject.h"

class PhysicsObject
{
public:
	PhysicsObject(RenderObject* renderObject, const Vector3& pos);
	virtual ~PhysicsObject();

	btRigidBody* getBody();
	void updateRenderObject();

private:

	btRigidBody* body;
	RenderObject *ro;
	Vector3 position;

};

