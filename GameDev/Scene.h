#pragma once
#include "PlayerGameObject.h"

class Scene {

public:

	Scene();
	virtual ~Scene();

	virtual void loadResources() = 0;
	virtual void unloadResources() = 0;

	virtual void loadObjects() = 0;
	virtual void unloadObjects() = 0;

	virtual void update() = 0;
	virtual void render() = 0;

	virtual void reset() = 0;

private:

	PlayerGameObject* player;

};