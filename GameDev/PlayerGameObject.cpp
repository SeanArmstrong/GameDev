#include "PlayerGameObject.h"

PlayerGameObject::PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t, const float movementSpeed)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new PlayerPhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
	this->movementSpeed = movementSpeed;
}


PlayerGameObject::~PlayerGameObject()
{
}

Vector3 PlayerGameObject::getPosition() const {
	btTransform trans;
	po->getBody()->getMotionState()->getWorldTransform(trans);
	return trans.getOrigin();
}

bool PlayerGameObject::isAlive() const {
	return alive;
}

int PlayerGameObject::getScore() const {
	return score;
}

void PlayerGameObject::setPosition(Vector3 view){
	btTransform trans;
	trans.setOrigin(btVector3(view.x, view.y, view.z));
	po->getBody()->setCenterOfMassTransform(trans);
}

void PlayerGameObject::setAlive(bool status){
	alive = status;
}

void PlayerGameObject::setScore(int newScore){
	score = newScore;
}

void PlayerGameObject::incrementScore(){
	score++;
}

void PlayerGameObject::update(){
	Vector3 angularVelocity = po->getBody()->getAngularVelocity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		po->getBody()->applyTorque(btVector3(forward.x, forward.y, forward.z) * movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		po->getBody()->applyTorque(btVector3(left.x, left.y, left.z) * movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		po->getBody()->applyTorque(btVector3(backward.x, backward.y, backward.z) * movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		po->getBody()->applyTorque(btVector3(right.x, right.y, right.z) * movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		if (!jumping){
			std::cout << "Jump";
			po->getBody()->applyImpulse(btVector3(jumpDirection.x * 15, jumpDirection.y * 15, 0), btVector3(0, 0, 0));
			jumping = true;
		}
	}

	if (jumping){
		timeSinceJumped += GameTimer::getDelta();
		std::cout << timeSinceJumped << std::endl;
		if (timeSinceJumped >= JUMPRESETTIME){
			jumping = false;
			timeSinceJumped = 0.0f;
		}
	}

	timeSinceShot += GameTimer::getDelta();

	po->updateRenderObject();
}

void PlayerGameObject::handleCollision(GameObject& obj){
	obj.handleCollision(*this);
}
void PlayerGameObject::handleCollision(PlayerGameObject& player){
	std::cout << "player - param player" << std::endl;
}

void PlayerGameObject::handleCollision(PlaneGameObject& plane){
	CollisionResponse::handleCollision(*this, plane);
}

void PlayerGameObject::handleCollision(CoinGameObject& coin){
	CollisionResponse::handleCollision(*this, coin);
}

void PlayerGameObject::handleCollision(PoolBallGameObject& poolball){
	std::cout << "player - param poolball" << std::endl;
}

GameObject* PlayerGameObject::spawnCube(){
	if (timeSinceShot > SHOOT_DELAY){
		timeSinceShot = 0;
		std::cout << forward << std::endl;
		return new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(getPosition().x, getPosition().y, getPosition().z) + (right * 5), 20, 1, ResourceManager::Instance().AddTexture("ground.jpg"));
	}
	return NULL;
}

void PlayerGameObject::setDirectionVectors(const Vector3& forward, const Vector3& backward,
											const Vector3& left, const Vector3& right){
	this->forward = forward;
	this->backward = backward;
	this->left = left;
	this->right = right;
	this->jumpDirection = Vector3::Cross(right, forward).unitVector();
}