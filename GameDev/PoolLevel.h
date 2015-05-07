#pragma once
#include "SinglePlayerLevel.h"
#include "SphereGameObject.h"
#include "PoolBallGameObject.h"
#include "AerialCamera.h"

/**
* @class	PoolLevel
*
* @brief	Class to represent single player pool level
*			Inherits from SinglePlayerLevel
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PoolLevel : public SinglePlayerLevel
{
public:
	/**
	* @fn	PoolLevel(sf::RenderWindow* w, SFMLRenderer* r);
	*
	* @brief	Constructor. Calls SinglePlayerLevel(w, r)
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	w	 	The SFML window
	* @param	r   	The renderer to add all objects
	*/
	PoolLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~PoolLevel();

	void* operator new(size_t i);
	void operator delete(void* p);
protected:

	/**
	* @fn	virtual void Initialise();
	*
	* @brief	Initialises the level
	*			
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void Initialise();

	/**
	* @fn	virtual void GameLogic();
	*
	* @brief	Level specific game logic
	*			Pool level camera is switched
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void GameLogic();

	/**
	* @fn	virtual void SetView();
	*
	* @brief	Sets up projection matrix and lighting
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void SetView();

	/**
	* @fn	virtual void LoadResources();
	*
	* @brief	Loads all resources used in this level
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void LoadResources();

	/**
	* @fn	virtual void LoadResources();
	*
	* @brief	Loads all resources used in this level
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void LoadMap();

	/**
	* @fn	virtual void LoadObjects();
	*
	* @brief	Setup for interative game objects
	*			Pool balls
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void LoadObjects();

	/**
	* @fn	virtual void LoadPlayer();
	*
	* @brief	Setup for player game object
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void LoadPlayer();

	/**
	* @fn	virtual void setObjectiveHUDText();
	*
	* @brief	Sets the objective for the level
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void setObjectiveHUDText();

private:

	// Pool level has second camera
	Camera* cameras[2];
	int cameraTracker;
	float timeSinceCameraChanged;
	float CAMERA_RESET_TIME = 1.0f;
};

