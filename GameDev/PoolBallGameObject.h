#pragma once
#include "GameObject.h"
#include "PoolBallPhysicsObject.h"

class PoolBallGameObject : public GameObject
{
public:
	enum Type { Red, Yellow, Black };

	PoolBallGameObject(Shader*s, const Vector3& position, const float mass, const float radius, const Type type, GLuint t = 0);
	virtual ~PoolBallGameObject();

	void removeFromGame();

	inline Type getType(){ return type;	}
	inline PlayerGameObject* getLastHitPlayer(){ return lastHitPlayer; }
	inline bool hasLastHitPlayer(){ return hasPlayer; }

	void setLastHitPlayer(PlayerGameObject* player);

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane);
	virtual void handleCollision(CoinGameObject& coin);
	virtual void handleCollision(PoolBallGameObject& poolball);

private:

	Type type;
	PlayerGameObject* lastHitPlayer;
	bool hasPlayer = false;

};

