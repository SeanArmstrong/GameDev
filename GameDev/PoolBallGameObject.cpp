#include "PoolBallGameObject.h"
#include "CollisionResponse.h"


PoolBallGameObject::PoolBallGameObject(Shader*s, const Vector3& position, const float mass, const float radius, const Type type, GLuint t){
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new PoolBallPhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
	this->type = type;
}


PoolBallGameObject::~PoolBallGameObject()
{
}

void PoolBallGameObject::handleCollision(GameObject& obj){
	obj.handleCollision(*this);
}

void PoolBallGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "PoolBall - param player" << std::endl;
}

void PoolBallGameObject::handleCollision(PlaneGameObject& plane){
	CollisionResponse::handleCollision(*this, plane);
}

void PoolBallGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "PoolBall - param coin" << std::endl;
}

void PoolBallGameObject::handleCollision(PoolBallGameObject& poolball){
	CollisionResponse::handleCollision(*this, poolball);
}