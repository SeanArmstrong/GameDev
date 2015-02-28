#include "CubeObject.h"


CubeObject::CubeObject()
{
	ro = new RenderObject(
		ResourceManager::Instance().GetMesh("cube"),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().GetTexture("brick.jpg"));
	ro->SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
	po = new PhysicsObject(ro, Vector3(0, 0, 0));
}


CubeObject::~CubeObject()
{
}
