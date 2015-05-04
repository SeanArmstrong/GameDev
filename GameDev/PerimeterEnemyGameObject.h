#pragma once
#include "GameObject.h"
#include "PerimeterEnemyPhysicsObject.h"

class PerimeterEnemyGameObject : public GameObject
{
public:
	PerimeterEnemyGameObject(Shader*s, const Vector3& startPosition, const Vector3& startDirection, const float radius,
		const float xDistance, const float zDistance, const float speed, GLuint t = 0);
	virtual ~PerimeterEnemyGameObject();

	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

