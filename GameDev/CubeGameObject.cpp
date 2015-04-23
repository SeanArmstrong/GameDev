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

void CubeGameObject::handleCollision(GameObject& obj){
	std::cout << "Cube - param gameobject " << std::endl;
	obj.handleCollision(*this);
}
void CubeGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "Cube - param player " << std::endl;
}
void CubeGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "Cube - param plane " << std::endl;
}

void CubeGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "cube - param coin" << std::endl;
}

void CubeGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "cube - param poolball" << std::endl;
}


