#pragma once
#include <vector>
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "PlayerFollowCamera.h"
#include "btBulletDynamicsCommon.h"
#include "World.h"
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

/**
* @class	Level
*
* @brief	Abstract class for the creation of all 
*			game levels. Provides functioanility for setting up
*			window, renderer for all levels and has functionaility
*			that will be present on all levels
*
* @author	Sean Armstrong
* @date	07/05/2015
*/

class Level {
public:

	/**
	* @fn	Level(sf::RenderWindow* w, SFMLRenderer* r);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	w	 	The SFML window
	* @param	r   	The renderer to add all objects
	*/
	Level(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level();

	/**
	* @fn	void Pause();
	*
	* @brief	Pauses the current level
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void Pause();

	/**
	* @fn	void Resume();
	*
	* @brief	Resumes the current level
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void Resume();

	/**
	* @fn	void PauseUpdate();
	*
	* @brief	Called to update the pause screen when visible
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void PauseUpdate();

	/**
	* @fn	void PauseUpdate();
	*
	* @brief	Called to render the pause screen when the level is paused
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void PauseRender();

	/**
	* @fn	void Update();
	*
	* @brief	Updates current level and calls specific level update method
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void Update();

	/**
	* @fn	void Update();
	*
	* @brief	Updates current level and calls specific level update method
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void Render();



	// Check the current level states
	inline bool Level::isGameWon(){ return (levelState == WON);	}
	inline bool Level::isGameLost(){ return (levelState == LOST); }
	inline bool Level::isGameFinished(){ return (levelState == FINISHED); }
	inline bool Level::isGamePaused(){ return (levelState == PAUSED); }
	inline bool Level::isGameQuitting(){ return (levelState == QUITTING); }
	
	/**
	* @fn	void getEndOfLevelMessage();
	*
	* @brief	Called once game is over. Result for
	*			the won/lost/endgame screen
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return	String - Message to display the user on next screen
	*/
	std::string getEndOfLevelMessage();

	/**
	* @fn	PauseHUD getPauseHUD() const;
	*
	* @brief	Called once game is over
	*			returns the message to display to
	*			the user on the won/lost/endgame screen
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return	PauseHUD - The levels pausedHUD
	*/
	PauseHUD getPauseHUD() const;

	// Pure abstract function
	virtual std::string getControlText() const = 0;

protected:
	// Pure Abstract Functions
	virtual void Initialise() = 0;
	virtual void UpdateLevel() = 0;
	virtual void RenderLevel() = 0;
	virtual void GameLogic() = 0;
	virtual void GeneralGameLogic() = 0;
	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;
	virtual void setObjectiveHUDText() = 0;

	/**
	* @fn	void removeDeletedObjects();
	*
	* @brief	Removes the deleted game objects from
	* 			the physics world and renderer
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void removeDeletedObjects();

	/**
	* @fn	void addWorldObject(GameObject* g);
	*
	* @brief	Adds g to the physics world, renderer via addToWorlds() 
	*			and tracked world objects
	* 			
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	g	 	Game Object to add to the world
	*/
	void addWorldObject(GameObject* g);

	/**
	* @fn	void addEventObject(GameObject* g);
	*
	* @brief	Adds g to the physics world and renderer via addToWorlds()
	*			and tracked event objects to be used by
	*			the physics callback
	*
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	g	 	Game Object to add to the world
	*/
	void addEventObject(GameObject* g);

	/**
	* @fn	void addToWorlds(GameObject* g);
	*
	* @brief	Adds g to physics world and renderer
	*			
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	g	 	Game Object to add to the world
	*/
	void addToWorlds(GameObject* g);

	/**
	* @fn	void rotateGravityRight();
	*
	* @brief	Rotates gravity
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void rotateGravityRight();

	/**
	* @fn		void rotateGravityLeft();
	*
	* @brief	Rotates gravity
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void rotateGravityLeft();

	// Game Window passed from GameState
	sf::RenderWindow* window;

	// Physics world (Bullet)
	World world;

	// Base camera for level
	Camera* cam;

	// Renderer to add objects too
	SFMLRenderer* renderer;

	// Visual Skybox
	Skybox sb;

	// World objects holds all level objects except event objects
	std::vector<GameObject*> worldObjects;

	// Event objects interact with one another and are used in bullet callback
	std::vector<GameObject*> eventObjects;

	// Base Player
	PlayerGameObject* player;

	// All players within the level
	std::vector<PlayerGameObject*> players;

	// Bool signifies end of game
	bool endLevel = false;

	// Timer for level which countsdown
	float timer;

	// Defines score to win
	int levelScore;

	// Gravity
	void setupGravity();
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

	// Extra HUDs
	PauseHUD pauseMenu;
	ControlHUD objectiveHUD;

};

