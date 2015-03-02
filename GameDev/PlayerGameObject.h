#pragma once
#include "GameObject.h"
#include "PlayerPhysicsObject.h"
#include "SphereGameObject.h"

class PlayerGameObject : public GameObject
{
public:
	PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t);
	~PlayerGameObject();

	virtual void update();

	void setPosition(Vector3 view);
	void moveForward();
	void moveBackwards();
	void moveLeft();
	void moveRight();
	void jump();
private:

	bool jumping;
	const float JUMPRESETTIME = 1.0f;
	float timeSinceJumped;
};

