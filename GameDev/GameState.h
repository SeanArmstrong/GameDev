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
#include "PlatformGameObject.h"
#include "World.h"
#include "MainMenuState.h"
#include "CameraNew.h"
#include "GameHUD.h"
#include "LevelWonState.h"
#include "LevelLostState.h"
#include "Level1.h"
#include "Level2.h"
#include "PoolLevel.h"

/**
 * @class	GameState
 *
 * @brief	A game state. Most complex state which actually builds and
 * 			runs the game. 
 * 			Future plans to have the game incased within scenes or levels
 * 			for now all game objects are built here and all game logic takes
 * 			place within the update function
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

class GameState : public State
{
public:
	GameState(sf::RenderWindow* w, const int level);
	virtual ~GameState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	/**
	 * @fn	virtual void GameState::Update(CoreEngine& engine);
	 *
	 * @brief	Updates the game every frame. Calls gameLogic to process
	 * 			the game logic and updates physics world and render world
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 */

	virtual void Update(CoreEngine& engine);

	/**
	 * @fn	virtual void GameState::Render();
	 *
	 * @brief	Renders game objects every frame
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual void Render();

	/**
	 * @fn	virtual void GameState::HandleEvents(CoreEngine& engine, sf::Event event);
	 *
	 * @brief	Handles the events such as changing state through ESC
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 * @param	event		  	The event.
	 */

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);

	/**
	 * @fn	void GameState::resetScene();
	 *
	 * @brief	Resets the scene.
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	//void resetScene();

	void LevelLost(CoreEngine& engine);
	void LevelWon(CoreEngine& engine);

protected:


private:


	/**
	 * @fn	void GameState::removeDeletedObjects();
	 *
	 * @brief	Removes the deleted game objects from
	 * 			the physics world and renderer
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	void removeDeletedObjects();

	Level* level;

	bool endGame = false;
};

