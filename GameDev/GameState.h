#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "btBulletDynamicsCommon.h"
#include "CubeObject.h"
#include "SphereObject.h"
#include "GameObject.h"
#include "World.h"


class GameState : public State
{
public:
	GameState();
	~GameState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(sf::Event event, const sf::RenderWindow& window);
	virtual void Update();
	virtual void Render();

protected:


private:

	World world;
	Camera cam;
	RenderObject o;
	std::vector<GameObject*> objects;
	bool mouseHeld;
};

