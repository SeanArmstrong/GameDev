#pragma once
#include "GameObject.h"
#include "CoinPhysicsObject.h"

class CoinGameObject : public GameObject
{
public:
	CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~CoinGameObject();

	virtual void update();
};

