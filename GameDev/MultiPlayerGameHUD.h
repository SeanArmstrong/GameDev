#pragma once
#include <string>
#include "PlayerGameObject.h"
#include <SFML/Graphics.hpp>

/**
* @class	MultiPlayerGameHUD
*
* @brief	HUD used to display scores and lives for all
*			players within the game
*
* @author	Sean Armstrong
* @date	07/05/2015
*/

class MultiPlayerGameHUD
{
public:

	/**
	* @fn	MultiPlayerGameHUD(const int width, const int height);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	width	 	The width of the window.
	* @param	height   	The height of the window.
	*/
	MultiPlayerGameHUD(const int width, const int height);
	~MultiPlayerGameHUD();

	/**
	* @fn	Update(const std::vector<PlayerGameObject*> players, const float& timer, const bool showLives = false);
	*
	* @brief	Sets the text for scorews and lives for all players given
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	players			players within the game.
	* @param	timer			time left within the game
	* @param	showLives		boolean to show the lives of the players.
	*/
	void Update(const std::vector<PlayerGameObject*> players, const float& timer, const bool showLives = false);

	/**
	* @fn	void Draw(sf::RenderWindow* window);
	*
	* @brief	Draws the text to the window
	* 			Needs the window to call draw
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	window	If non-null, the window.
	*/
	void Draw(sf::RenderWindow* window);

private:

	std::string scoreInfo;
	std::string timerInfo;
	std::string lifeInfo;
	sf::Text scoreText;
	sf::Text timerText;
	sf::Text lifeText;
	sf::Font font;
};

