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
	GameObject(){};
	virtual ~GameObject();

	/* Physical and Graphical World Methods */

	void addPhysicsObjectToWorld(btDynamicsWorld& world);
	void addRenderObjectToWorld(SFMLRenderer& renderer);
	void removePhysicsObjectFromWorld(btDynamicsWorld& world);
	void removeRenderObjectFromWorld(SFMLRenderer& renderer);

	/* Physical and Graphical World Methods */

	/* Getters */
	
	RenderObject* getRenderObject();
	PhysicsObject* getPhysicsObject();
	bool getExistsInWorld();

	/* End Getters */

	/* Setters */

	void setExistsInWorld(bool status);
	/* End Setters */

	virtual void update();

	/* Collisions */

	virtual void handleCollision(GameObject& obj) = 0;
	virtual void handleCollision(PlayerGameObject& player)= 0;
	virtual void handleCollision(PlaneGameObject& plane) = 0;
	virtual void handleCollision(CoinGameObject& coin) = 0;
	/* End Collisions */

protected:
	/* Graphical Representation */
	RenderObject* ro;
	/* Physical Representation*/
	PhysicsObject* po;

	bool existsInWorld = true;
	//GameObject* parent;
	//std::vector<GameObject> children;

};

