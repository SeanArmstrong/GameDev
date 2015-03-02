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
#include "CoinGameObject.h"
#include "PlaneGameObject.h"
#include "World.h"
#include "MainMenuState.h"
#include "CameraNew.h"

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

	void resetScene();
protected:


private:

	void loadScene();

	World world;
	Camera cam;
	CameraNew CamNew;
	RenderObject o;
	std::vector<GameObject*> worldObjects;
	float rotateAmount;

	PlayerGameObject* player;

	bool mouseHeld;
	bool endGame = false;
};

