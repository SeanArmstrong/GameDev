#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"

class PlatformGameObject : public GameObject
{
public:
	PlatformGameObject(Shader*s, const Vector3& position, const float mass,
			const float length, const float height, const float depth, GLuint t = 0);
	virtual ~PlatformGameObject();


	void handleCollision(GameObject& obj);
	void handleCollision(PlayerGameObject& player);
	void handleCollision(PlaneGameObject& plane);
	void handleCollision(CoinGameObject& coin);
	virtual void handleCollision(PoolBallGameObject& poolball);
};

