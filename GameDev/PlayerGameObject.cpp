#include "PlayerGameObject.h"

PlayerGameObject::PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t, const unsigned int lives, const float movementSpeed)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new PlayerPhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
	this->movementSpeed = movementSpeed;
	this->startingPosition = position;
	this->controlSet = PlayerInputManager::Instance().getControlSet();
	this->lives = lives * 2;
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
	if (PlayerInputManager::Instance().MovePlayerForward(this->controlSet)){
		po->getBody()->applyTorque(btVector3(forward.x, forward.y, forward.z) * movementSpeed);
	}
	if (PlayerInputManager::Instance().MovePlayerLeft(this->controlSet)){
		po->getBody()->applyTorque(btVector3(left.x, left.y, left.z) * movementSpeed);
	}
	if (PlayerInputManager::Instance().MovePlayerBackward(this->controlSet)){
		po->getBody()->applyTorque(btVector3(backward.x, backward.y, backward.z) * movementSpeed);
	}
	if (PlayerInputManager::Instance().MovePlayerRight(this->controlSet)){
		po->getBody()->applyTorque(btVector3(right.x, right.y, right.z) * movementSpeed);
	}
	if (PlayerInputManager::Instance().JumpPlayer(this->controlSet)){
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
	CollisionResponse::handleCollision(*this, poolball);
}
void PlayerGameObject::handleCollision(CheckpointGameObject& checkpoint){
	CollisionResponse::handleCollision(*this, checkpoint);
}

void PlayerGameObject::handleCollision(EndGameGameObject& endGame){
	CollisionResponse::handleCollision(*this, endGame);
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

void PlayerGameObject::resetPlayerPosition(){
	setPosition(startingPosition);
	po->getBody()->setAngularVelocity(btVector3(0, 0, 0));
	po->getBody()->setLinearVelocity(btVector3(0, 0, 0));
}

void PlayerGameObject::setPlayerLives(const int lives){
	this->lives = lives * 2;
}

void PlayerGameObject::looseALife(){
	lives--;
}

int PlayerGameObject::getPlayerLives() const{
	return lives/2;
}

void PlayerGameObject::updateStartingPosition(const Vector3& newPosition){
	this->startingPosition = newPosition;
}

void PlayerGameObject::setEndGoalReached(const bool option){
	this->endGoalReached = option;
}
