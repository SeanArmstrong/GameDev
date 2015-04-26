#pragma once
#include "PlaneGameObject.h"

class HazeGameObject : public PlaneGameObject
{
public:
	HazeGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	virtual ~HazeGameObject();
};

