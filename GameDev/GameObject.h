#pragma once
#include <vector>
#include "RenderObject.h"
#include "PhysicsObject.h"
#include "SFMLRenderer.h"
#include "btBulletDynamicsCommon.h"
#include "ResourceManager.h"
#include "GameTimer.h"

class World;
class PlayerGameObject;
class PlaneGameObject;
class CoinGameObject;

class GameObject
{
public:
	//GameObject();
	//virtual ~GameObject();

	void addPhysicsObjectToWorld(btDynamicsWorld& world);
	void addRenderObjectToWorld(SFMLRenderer& renderer);

	/* Getters */
	
	RenderObject* getRenderObject();
	PhysicsObject* getPhysicsObject();
	bool getExistsInWorld();

	/* Setters */
	void setExistsInWorld(bool status);

	virtual void update();

	//Collision Methods
	virtual void handleCollision(GameObject& obj) = 0;
	virtual void handleCollision(PlayerGameObject& player)= 0;
	virtual void handleCollision(PlaneGameObject& plane) = 0;
	virtual void handleCollision(CoinGameObject& coin) = 0;
protected:
	RenderObject* ro;
	PhysicsObject* po;

	bool existsInWorld = true;
	//GameObject* parent;
	//std::vector<GameObject> children;

};

