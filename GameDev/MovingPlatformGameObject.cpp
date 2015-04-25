#include "MovingPlatformGameObject.h"


MovingPlatformGameObject::MovingPlatformGameObject(Shader*s, const Vector3& position, const float mass,
	const float width, const float height, const float depth, const Vector3& direction,
	const float distance, const float speed, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(width, height, depth)));
	this->po = new MovingPlatformPhysicsObject(ro, position, mass, width, height, depth, direction, distance, speed);
	this->po->getBody()->setUserPointer((void*)this);
}


MovingPlatformGameObject::~MovingPlatformGameObject()
{
}

void MovingPlatformGameObject::handleCollision(GameObject& obj){
	std::cout << "moving platform - param gameobject " << std::endl;
}

void MovingPlatformGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "moving platform - param player " << std::endl;
}

void MovingPlatformGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "moving platform - param plane " << std::endl;
}

void MovingPlatformGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "moving platform - param coin" << std::endl;
}

void MovingPlatformGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "moving platform - param poolball" << std::endl;
}
