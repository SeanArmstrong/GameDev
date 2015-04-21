#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "btBulletDynamicsCommon.h"
#include "World.h"
#include "CameraNew.h"
#include "GameHUD.h"
#include "Skybox.h"

class Level {
public:
	Level(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level();

	virtual void Initialise() = 0;
	void Pause();
	void Resume();
	virtual void Update(CoreEngine& engine);
	virtual void GameLogic(CoreEngine& engine) = 0;
	virtual void Render();

	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;

protected:

	void removeDeletedObjects();

	sf::RenderWindow* window;

	World world;
	Camera cam;
	GameHUD hud;
	SFMLRenderer* renderer;
	Skybox sb;

	std::vector<GameObject*> worldObjects;
	std::vector<GameObject*> eventObjects;

	PlayerGameObject* player;

	bool mouseHeld;
	bool endLevel = false;

	float timer;

};

