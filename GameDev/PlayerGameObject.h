#pragma once
#include "GameObject.h"
#include "PlayerPhysicsObject.h"
#include <SFML\Window.hpp>
#include "PlaneGameObject.h"
#include "CollisionResponse.h"
#include "CubeGameObject.h"

class PlayerGameObject : public GameObject
{
public:
	PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t);
	~PlayerGameObject();

	/* Getters */
	Vector3 getPosition() const;
	bool isAlive() const;
	int getScore() const;

	/* Settters */
	void setPosition(Vector3 view);
	void setAlive(bool status);
	void setScore(int newScore);
	void increaseScore();
	
	virtual void update();

	/* Collision */
	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);

	/* Game Logic */
	GameObject* spawnCube();


private:

	/* Life Variables */
	bool alive = true;

	/* Progress Variable */
	int score = 0;

	/* Movement variables */
	float movementSpeed = 10.0f;
	bool jumping;
	const float JUMPRESETTIME = 1.0f;
	float timeSinceJumped;

	/* Weapon options */
	const float SHOOT_DELAY = 2.0f;
	float timeSinceShot = 0;
};

