#pragma once
#include "SinglePlayerLevel.h"

/**
* @class	Level1
*
* @brief	Class to represent 1st single player level
*			Inherits from SinglePlayerLevel
*			This was originally game state from first submission
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class Level1 : public SinglePlayerLevel {
public:

	/**
	* @fn	Level3(sf::RenderWindow* w, SFMLRenderer* r);
	*
	* @brief	Constructor. Calls SinglePlayerLevel(w, r)
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	w	 	The SFML window
	* @param	r   	The renderer to add all objects
	*/
	Level1(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level1();

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
	* @fn	virtual void LoadMap();
	*
	* @brief	Setup for interative game objects
	*			( Pool Balls)
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

};

