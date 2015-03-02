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
void PlayerGameObject::setPosition(Vector3 view){
	btTransform trans;
	trans.setOrigin(btVector3(view.x, view.y, view.z));
	po->getBody()->setCenterOfMassTransform(trans);
}

void PlayerGameObject::update(){

	if (jumping){
		timeSinceJumped += GameTimer::getDelta();
		std::cout << timeSinceJumped << std::endl;
		if (timeSinceJumped >= JUMPRESETTIME){
			jumping = false;
			timeSinceJumped = 0.0f;
		}
	}

	po->updateRenderObject();

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
	if (!jumping){
		std::cout << "Jump";
		po->getBody()->applyImpulse(btVector3(0, 10, 0), po->getBody()->getCenterOfMassPosition());
		jumping = true;
	}
}
