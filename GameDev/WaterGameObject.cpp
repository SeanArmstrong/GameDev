#include "WaterGameObject.h"


WaterGameObject::WaterGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly)
	: PlaneGameObject(normal, mass, distance, s, t, tca) {
}


WaterGameObject::~WaterGameObject()
{
}
