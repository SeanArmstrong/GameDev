#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"

class PlatformGameObject : public GameObject
{
public:
	PlatformGameObject(Shader*s, const Vector3& position, const float mass,
			const float length, const float height, const float depth, GLuint t = 0);
	virtual ~PlatformGameObject();


	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);
	virtual void handleCollision(PoolBallGameObject& poolball);
};

