#include "ConvexGameObject.h"


ConvexGameObject::ConvexGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t){
	Mesh* m = ResourceManager::Instance().GetMesh(meshName);
	this->ro = new RenderObject(m, s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(scale,scale,scale)));
	this->po = new ConvexPhysicsObject(this->ro, position, mass, m, scale);
}


ConvexGameObject::~ConvexGameObject()
{
}

void ConvexGameObject::handleCollision(GameObject& obj){}
void ConvexGameObject::handleCollision(PlayerGameObject& player){}
void ConvexGameObject::handleCollision(PlaneGameObject& plane){}
void ConvexGameObject::handleCollision(CoinGameObject& coin){}