#include "CheckpointGameObject.h"


CheckpointGameObject::CheckpointGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, GLuint t, const bool hasRenderObject)
{
	this->activated = false;
	if (hasRenderObject){
		this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
		this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(lengthHeightDepth));
		this->po = new PlatformPhysicsObject(ro, position, mass, lengthHeightDepth, false);
	}
	else{
		this->po = new PlatformPhysicsObject(NULL, position, mass, lengthHeightDepth, false);
	}
	this->po->getBody()->setUserPointer((void*)this);
}


CheckpointGameObject::~CheckpointGameObject()
{
}

bool CheckpointGameObject::isActivated(){
	return activated;
}

void CheckpointGameObject::setActivated(bool option){
	activated = option;
}

void CheckpointGameObject::handleCollision(GameObject& obj){
	obj.handleCollision(*this);
}
void CheckpointGameObject::handleCollision(PlayerGameObject& player){
	CollisionResponse::handleCollision(*this, player);
}
