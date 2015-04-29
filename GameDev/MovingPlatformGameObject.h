#pragma once
#include "GameObject.h"
#include "MovingPlatformPhysicsObject.h"

class MovingPlatformGameObject : public GameObject
{
public:
	MovingPlatformGameObject(Shader*s, const Vector3& position, const float mass,
		const float width, const float height, const float depth, const Vector3& direction, 
		const float distance, const float speed, GLuint t = 0);

	virtual ~MovingPlatformGameObject();


	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);
	virtual void handleCollision(PoolBallGameObject& poolball);
};
