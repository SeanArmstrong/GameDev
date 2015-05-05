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
#include "HazeGameObject.h"
#include "MultiPlayerGameHUD.h"
#include "PauseHUD.h"
#include "PerimeterEnemyGameObject.h"

class Level {
public:
	Level(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level();

	virtual void Initialise() = 0;
	void Pause();
	void PauseUpdate();
	void PauseRender();
	void Resume();
	void Update();
	void Render();

	virtual void UpdateLevel() = 0;
	virtual void RenderLevel() = 0;

	virtual void GameLogic() = 0;
	virtual void GeneralGameLogic() = 0;

	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;

	inline bool Level::isGameWon(){
		return (levelState == WON);
	}
	inline bool Level::isGameLost(){
		return (levelState == LOST);
	}
	inline bool Level::isGameFinished(){
		return (levelState == FINISHED);
	}
	inline bool Level::isGamePaused(){
		return (levelState == PAUSED);
	}
	inline bool Level::isGameQuitting(){
		return (levelState == QUITTING);
	}
	
	std::string getEndOfLevelMessage();
	virtual std::string getControlText() const = 0;
	virtual void setObjectiveHUDText() = 0;

	PauseHUD Level::getPauseHUD() const;

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
	SFMLRenderer* renderer;
	Skybox sb;

	std::vector<GameObject*> worldObjects;
	std::vector<GameObject*> eventObjects;

	PlayerGameObject* player;
	std::vector<PlayerGameObject*> players;

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

	// Game State
	enum LevelState { PLAYING, WON, LOST, FINISHED, PAUSED, QUITTING };
	LevelState levelState = PLAYING;
	std::string endOfGameMessage;

	PauseHUD pauseMenu;
	ControlHUD objectiveHUD;
	void setupGravity();

private:
};

