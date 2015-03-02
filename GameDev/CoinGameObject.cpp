#include "CoinGameObject.h"


CoinGameObject::CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	ro = new RenderObject(ResourceManager::Instance().GetMesh("coin"), s, t);
	ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	po = new CoinPhysicsObject(ro, position, mass, radius);
}


CoinGameObject::~CoinGameObject()
{
}

void CoinGameObject::update(){
	po->updateRenderObject();
}
