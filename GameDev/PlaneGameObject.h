#pragma once
#include "GameObject.h"
#include "PlanePhysicsObject.h"

class PlaneGameObject :public GameObject
{
public:
	PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0);
	virtual ~PlaneGameObject();
};

