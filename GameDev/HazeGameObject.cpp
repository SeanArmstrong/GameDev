#include "HazeGameObject.h"


HazeGameObject::HazeGameObject(Vector3& normal, const float mass, const float distance, Shader*s, GLuint t, PlayerContactAction tca)
	: PlaneGameObject(normal, mass, distance, s, t, tca) {
	this->ro->SetTexture1(ResourceManager::Instance().AddTexture("terrain.jpg"));
	this->ro->SetCubeMap(ResourceManager::Instance().GetTexture("rustskybox"));
}


HazeGameObject::~HazeGameObject()
{
}
