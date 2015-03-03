#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "btBulletDynamicsCommon.h"
#include "GameObject.h"
#include "PlayerGameObject.h"
#include "CoinGameObject.h"
#include "PlaneGameObject.h"
#include "CubeGameObject.h"
#include "SphereGameObject.h"
#include "World.h"
#include "MainMenuState.h"
#include "CameraNew.h"
#include "ThirdPersonCamera.h"

class GameState : public State
{
public:
	GameState(const float& width, const float& height);
	virtual  ~GameState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void Update(CoreEngine& engine);
	virtual void Render();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);

	void resetScene();
protected:


private:

	void loadScene();

	World world;
	Camera cam;
	std::vector<GameObject*> worldObjects;
	std::vector<GameObject*> eventObjects;

	PlayerGameObject* player;

	bool mouseHeld;
	bool endGame = false;
};

