#pragma once
#include "GameObject.h"
#include "ConcavePhysicsObject.h"

class ConcaveGameObject : public GameObject
{
public:
	ConcaveGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t = 0);
	~ConcaveGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);
};

