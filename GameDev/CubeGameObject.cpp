#include "CubeGameObject.h"

CubeGameObject::CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(length, length, length)));
	this->po = new CubePhysicsObject(ro, position, mass, length);
	this->po->getBody()->setUserPointer((void*)this);
}


CubeGameObject::~CubeGameObject()
{
}

