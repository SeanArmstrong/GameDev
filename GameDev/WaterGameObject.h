#pragma once
#include "PlaneGameObject.h"

class WaterGameObject : public PlaneGameObject
{
public:
	WaterGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	virtual ~WaterGameObject();
};

