#include "ConcaveGameObject.h"


ConcaveGameObject::ConcaveGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t){
	Mesh* m = ResourceManager::Instance().GetMesh(meshName);
	this->ro = new RenderObject(m, s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(scale, scale, scale)));
	this->po = new ConcavePhysicsObject(this->ro, position, mass, m, scale);
}


ConcaveGameObject::~ConcaveGameObject()
{
}

void ConcaveGameObject::handleCollision(GameObject& obj){}
void ConcaveGameObject::handleCollision(PlayerGameObject& player){}
void ConcaveGameObject::handleCollision(PlaneGameObject& plane){}
void ConcaveGameObject::handleCollision(CoinGameObject& coin){}
