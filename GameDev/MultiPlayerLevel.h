#pragma once
#include "Level.h"

/**
* @class	MultiPlayerLevel
*
* @brief	Abstract level class for all Multi player levels
*			inherits from Level
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class MultiPlayerLevel : public Level
{
public:

	/**
	* @fn	MultiPlayerLevel(sf::RenderWindow* w, SFMLRenderer* r);
	*
	* @brief	Constructor. Calls Level(w, r)
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	w	 	The SFML window
	* @param	r   	The renderer to add all objects
	*/
	MultiPlayerLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~MultiPlayerLevel();

	/**
	* @fn	virtual void UpdateLevel();
	*
	* @brief	Basic update call for all multi player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void UpdateLevel();

	/**
	* @fn	virtual void RenderLevel();
	*
	* @brief	Basic render call for all multi player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void RenderLevel();

	/**
	* @fn	virtual void GeneralGameLogic();
	*
	* @brief	Basic game logic for all multi player levels
	*			can be overwridden
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	virtual void GeneralGameLogic();



protected:
	// Abstract Functions
	virtual void Initialise() = 0;
	virtual void GameLogic() = 0;
	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;
	virtual void setObjectiveHUDText() = 0;

	virtual std::string getControlText() const;

	/**
	* @fn	bool allPlayersDead();
	*
	* @brief	Check to see if all players have lost
	*			all their lives
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return	true is all players lost all lives
	*/
	bool allPlayersDead();

	// Game HUD to show all players info
	MultiPlayerGameHUD hud;

private:

};

