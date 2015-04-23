#pragma once
#include "PhysicsObject.h"

class StaticConcavePhysicsObject : public PhysicsObject
{
public:
	StaticConcavePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	~StaticConcavePhysicsObject();

	void updateRenderObject();

private: 	
	btTriangleMesh* tMesh;
	float scale;
	Mesh* mesh;
};

