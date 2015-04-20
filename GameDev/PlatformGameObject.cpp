#include "PlatformGameObject.h"

PlatformGameObject::PlatformGameObject(Shader*s, const Vector3& position, const float mass, 
						const float width, const float height, const float depth, GLuint t) {

	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(width, height, depth)));
	this->po = new PlatformPhysicsObject(ro, position, mass, width, height, depth);
	this->po->getBody()->setUserPointer((void*)this);
}


PlatformGameObject::~PlatformGameObject()
{
}

void PlatformGameObject::handleCollision(GameObject& obj){
	std::cout << "Platform - param gameobject " << std::endl;
}
void PlatformGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "Platform - param player " << std::endl;
}
void PlatformGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "Platform - param plane " << std::endl;
}

void PlatformGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "Platform - param coin" << std::endl;
}