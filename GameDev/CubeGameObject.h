#pragma once
#include "GameObject.h"
#include "CubePhysicsObject.h"

class CubeGameObject : public GameObject
{
public:
	CubeGameObject(Shader*s, const Vector3& position, const float mass, const float length, GLuint t = 0);
	virtual ~CubeGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);

};

