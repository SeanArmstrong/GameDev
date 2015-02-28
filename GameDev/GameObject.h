#pragma once
#include <vector>
#include "RenderObject.h"
#include "PhysicsObject.h"
#include "SFMLRenderer.h"
#include "btBulletDynamicsCommon.h"
#include "ResourceManager.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void addPhysicsObjectToWorld(btDynamicsWorld& world);
	void addRenderObjectToWorld(SFMLRenderer& renderer);

	//void addChild(const GameObject& child);

	void update();

protected:
	RenderObject* ro;
	PhysicsObject* po;

	//GameObject* parent;
	//std::vector<GameObject> children;

};

