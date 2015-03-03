#include "PlaneGameObject.h"


PlaneGameObject::PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s, GLuint t)
{
	if (s){
		this->ro = new RenderObject(
			ResourceManager::Instance().AddMeshFromMethod("plane", ResourceManager::MeshGenerationMethods::GENERATE_QUAD), 
			s, 
			t);
	}
	this->po = new PlanePhysicsObject(NULL, normal, mass, distance);
	this->po->getBody()->setUserPointer((void*)this);
}


PlaneGameObject::~PlaneGameObject()
{
}

bool PlaneGameObject::isDeadly(){
	return deadly;
}


void PlaneGameObject::handleCollision(GameObject& obj){
	obj.handleCollision(*this);
}
void PlaneGameObject::handleCollision(PlayerGameObject& player){
	CollisionResponse::handleCollision(player, *this);
}
void PlaneGameObject::handleCollision(PlaneGameObject& plane){
	// Plane Plane collision 
}

void PlaneGameObject::handleCollision(CoinGameObject& coin){
	// plane coin collision
}

