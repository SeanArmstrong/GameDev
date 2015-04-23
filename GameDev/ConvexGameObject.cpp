#include "ConvexGameObject.h"


ConvexGameObject::ConvexGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t){
	Mesh* m = ResourceManager::Instance().GetMesh(meshName);
	this->ro = new RenderObject(m, s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(scale,scale,scale)));
	this->po = new ConvexPhysicsObject(this->ro, position, mass, m, scale);
	this->po->getBody()->setUserPointer((void*)this);
}


ConvexGameObject::~ConvexGameObject()
{
}

void ConvexGameObject::handleCollision(GameObject& obj){
	std::cout << "convex - param obj" << std::endl;
}
void ConvexGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "convex - param player" << std::endl;
}
void ConvexGameObject::handleCollision(PlaneGameObject& plane){
	std::cout << "convex - param plane" << std::endl;
}
void ConvexGameObject::handleCollision(CoinGameObject& coin){
	std::cout << "convex - param coin" << std::endl;
}

void ConvexGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "convex - param poolball" << std::endl;
}

