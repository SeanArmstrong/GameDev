#pragma once
#include "GameObject.h"

class OneUpGameObject : public GameObject
{
public:
	OneUpGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~OneUpGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

