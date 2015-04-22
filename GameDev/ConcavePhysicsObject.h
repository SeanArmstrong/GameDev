#pragma once
#include "PhysicsObject.h"

class ConcavePhysicsObject : public PhysicsObject
{
public:
	ConcavePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	~ConcavePhysicsObject();

	void updateRenderObject();

private: 	

	float scale;
	Mesh* mesh;
};

