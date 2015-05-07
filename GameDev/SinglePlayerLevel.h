#pragma once
#include "Level.h"
#include "EndGameGameObject.h"


/**
* @class	SinglePlayerLevel
*
* @brief	Abstract level class for all single player levels
*			inherits from Level
*			
* @author	Sean Armstrong
* @date	07/05/2015
*/

class SinglePlayerLevel : public Level
{
public:

	/**
	* @fn	SinglePlayerLevel(sf::RenderWindow* w, SFMLRenderer* r);
	*
	* @brief	Constructor. Calls Level(w, r)
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	w	 	The SFML window
	* @param	r   	The renderer to add all objects
	*/
	SinglePlayerLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~SinglePlayerLevel();

	/**
	* @fn	virtual void UpdateLevel();
	*
	* @brief	Basic update call for all single player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void UpdateLevel();

	/**
	* @fn	virtual void RenderLevel();
	*
	* @brief	Basic render call for all single player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void RenderLevel();

	/**
	* @fn	virtual void GeneralGameLogic();
	*
	* @brief	Basic game logic for all single player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void GeneralGameLogic();


protected:
	// Pure Abstract Functions
	virtual void Initialise() = 0;
	virtual void GameLogic() = 0;
	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;
	virtual void setObjectiveHUDText() = 0;

	virtual std::string getControlText() const;

	// Game HUD to show player info
	GameHUD hud;

};

