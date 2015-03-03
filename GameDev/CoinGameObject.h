#pragma once
#include "GameObject.h"
#include "CoinPhysicsObject.h"

class CoinGameObject : public GameObject
{
public:
	CoinGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~CoinGameObject();
	
	/* Getters */

	/* Setters */

	/* Methods */

	void removeFromGame(); //removeFromScene
	
	virtual void update();

	/* Collisions */

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);

};

