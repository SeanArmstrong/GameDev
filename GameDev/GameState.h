#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "btBulletDynamicsCommon.h"
#include "CubeGameObject.h"
#include "SphereGameObject.h"
#include "GameObject.h"
#include "PlayerGameObject.h"
#include "World.h"
#include "MainMenuState.h"


class GameState : public State
{
public:
	GameState(const float& width, const float& height);
	virtual  ~GameState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void Update();
	virtual void Render();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);

protected:


private:

	World world;
	Camera cam;
	RenderObject o;
	std::vector<GameObject*> worldObjects;

	PlayerGameObject* player;

	bool mouseHeld;
};

