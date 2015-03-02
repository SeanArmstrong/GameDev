#pragma once
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "RenderObject.h"

class PhysicsObject
{
public:
	PhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass);
	virtual ~PhysicsObject();


	btRigidBody* getBody() const;
	virtual void updateRenderObject() = 0;
	bool hasRenderObject();

protected:

	btRigidBody* body;
	btCollisionShape* shape;
	float mass;

	RenderObject *ro;
	Vector3 position;

};

