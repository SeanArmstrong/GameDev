#pragma once
#include "GameObject.h"
#include "PlanePhysicsObject.h"
#include "PlaneGameObject.h"
#include "CollisionResponse.h"

class PlaneGameObject :public GameObject
{
public:
	PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0);
	virtual ~PlaneGameObject();
	
	/* Getters */
	bool isDeadly();

	/* Setters */

	/* Collision */
	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);

private:

	bool deadly = true;
};

