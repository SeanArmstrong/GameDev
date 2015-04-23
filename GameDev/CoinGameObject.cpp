#include "CoinGameObject.h"
#include "CollisionResponse.h"

CoinGameObject::CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("coin"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new CoinPhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
}


CoinGameObject::~CoinGameObject()
{
}

void CoinGameObject::removeFromGame(){
	po->getBody()->setCollisionFlags(0);
	delete ro;
}

void CoinGameObject::update(){
	po->updateRenderObject();
}

void CoinGameObject::handleCollision(GameObject& obj){
	std::cout << "coin - param gameobject" << std::endl;
	obj.handleCollision(*this);
}
void CoinGameObject::handleCollision(PlayerGameObject& player){
	CollisionResponse::handleCollision(player, *this);
}
void CoinGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "coin - param plane" << std::endl;
}

void CoinGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "coin - param coin" << std::endl;
}

void CoinGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "coin - param poolball" << std::endl;
}
