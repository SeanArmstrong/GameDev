#include "ConcaveGameObject.h"


ConcaveGameObject::ConcaveGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t){
	Mesh* m = ResourceManager::Instance().GetMesh(meshName);
	this->ro = new RenderObject(m, s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(scale, scale, scale)));
	this->po = new StaticConcavePhysicsObject(this->ro, position, mass, m, scale);
	this->po->getBody()->setUserPointer((void*)this);
}


ConcaveGameObject::~ConcaveGameObject()
{
}

void ConcaveGameObject::handleCollision(GameObject& obj){
	std::cout << "concave - param obj" << std::endl;
}
void ConcaveGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "concave - param player" << std::endl;
}
void ConcaveGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "concave - param plane" << std::endl;
}
void ConcaveGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "concave - param coin" << std::endl;
}

void ConcaveGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "concave - param poolball" << std::endl;
}