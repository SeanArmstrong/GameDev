#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"
#include "CollisionResponse.h"

class CheckpointGameObject : public GameObject
{
public:
	CheckpointGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, GLuint t = 0, const bool hasRenderObject = false);
	virtual ~CheckpointGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}

	bool isActivated();
	void setActivated(bool option);

private:

	bool activated;
};

