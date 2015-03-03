#pragma once
#include "GameObject.h"
#include "SpherePhysicsObject.h"

class SphereGameObject : public GameObject
{
public:
	SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~SphereGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);
};

