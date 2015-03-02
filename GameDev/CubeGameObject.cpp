#include "CubeGameObject.h"


CubeGameObject::CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t)
{
	ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(length, length, length)));
	po = new CubePhysicsObject(ro, position, mass, length);
}


CubeGameObject::~CubeGameObject()
{
}

