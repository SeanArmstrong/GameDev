#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "PlayerFollowCamera.h"
#include "btBulletDynamicsCommon.h"
#include "World.h"
#include "CameraNew.h"
#include "GameHUD.h"
#include "Skybox.h"
#include "PlatformGameObject.h"
#include "ConvexGameObject.h"
#include "ConcaveGameObject.h"
#include "MovingPlatformGameObject.h"

class Level {
public:
	Level(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level();

	virtual void Initialise() = 0;
	void Pause();
	void Resume();
	virtual void Update();
	virtual void Render();

	virtual void GameLogic() = 0;
	void GeneralGameLogic();

	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;

	inline bool Level::isGameWon(){
		return (levelState == WON) ? true : false;
	}
	inline bool Level::isGameLost(){
		return (levelState == LOST) ? true : false;
	}

protected:

	void removeDeletedObjects();
	void addWorldObject(GameObject* g);
	void addEventObject(GameObject* g);
	void addToWorlds(GameObject* g);

	void rotateGravityRight();
	void rotateGravityLeft();

	sf::RenderWindow* window;

	World world;
	Camera* cam;
	GameHUD hud;
	SFMLRenderer* renderer;
	Skybox sb;

	std::vector<GameObject*> worldObjects;
	std::vector<GameObject*> eventObjects;

	PlayerGameObject* player;

	bool mouseHeld;
	bool endLevel = false;

	float timer;

	int levelScore;

	// Gravity
	bool gravityOn;
	btVector3 gravityDirections[4];
	btVector3 upVectorDirections[4];
	int gravityTracker;
	const float GRAVITY_RESET_TIME = 1.0f;
	float timeSinceGravityChanged;


private:
	enum LevelState { PLAYING, WON, LOST };
	LevelState levelState = PLAYING;
	void setUpGravity();
};

