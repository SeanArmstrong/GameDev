#pragma once
#include "GameObject.h"
#include "CubePhysicsObject.h"

class CubeGameObject : public GameObject
{
public:
	CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t = 0);
	virtual ~CubeGameObject();
};

