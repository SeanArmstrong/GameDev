#include "PlayerGameObject.h"


PlayerGameObject::PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	po = new PlayerPhysicsObject(ro, position, mass, radius);
}


PlayerGameObject::~PlayerGameObject()
{
}

void PlayerGameObject::moveForward(){
	std::cout << "Forward";
	po->getBody()->applyImpulse(btVector3(0, 0, -1), po->getBody()->getCenterOfMassPosition());
}
void PlayerGameObject::moveBackwards(){
	std::cout << "Backward";
	po->getBody()->applyImpulse(btVector3(0, 0, 1), po->getBody()->getCenterOfMassPosition());
}
void PlayerGameObject::moveLeft(){
	std::cout << "Left";
	po->getBody()->applyImpulse(btVector3(-1, 0, 0), po->getBody()->getCenterOfMassPosition());
}
void PlayerGameObject::moveRight(){
	std::cout << "Right";
	po->getBody()->applyImpulse(btVector3(1, 0, 0), po->getBody()->getCenterOfMassPosition());
}

void PlayerGameObject::jump(){
	std::cout << "Jump";
	po->getBody()->applyImpulse(btVector3(0, 5, 0), po->getBody()->getCenterOfMassPosition());
}
