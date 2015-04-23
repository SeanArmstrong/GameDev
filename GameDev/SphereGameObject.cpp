#include "SphereGameObject.h"


SphereGameObject::SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new SpherePhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
}


SphereGameObject::~SphereGameObject()
{
}


void SphereGameObject::handleCollision(GameObject& obj){
	std::cout << "Sphere - param obj" << std::endl;
}


void SphereGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "Sphere - param player" << std::endl;
}

void SphereGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "Sphere - param plane" << std::endl;
}

void SphereGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "Sphere - param coin" << std::endl;
}

void SphereGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "Sphere - param poolball" << std::endl;
}
