#pragma once
#include "GameObject.h"
#include "PlayerPhysicsObject.h"
#include "SphereGameObject.h"

class PlayerGameObject : public GameObject
{
public:
	PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t);
	~PlayerGameObject();

	void moveForward();
	void moveBackwards();
	void moveLeft();
	void moveRight();
	void jump();

};

