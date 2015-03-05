#pragma once
#include <string>
#include "PlayerGameObject.h"
#include <SFML/Graphics.hpp>

/* At the moment this is almost identical to DebugHUD however this
	will be changed to use a renderer with a orthographic projection
	that is drawn to the screen infront of everything else (setting depth buffer)
	hence the seperate class without inheriting or anything like that
*/

/**
 * @class	GameHUD
 *
 * @brief	Shows score and game timer in the current game
 * 			
 * 			At the moment this is almost identical to DebugHUD however this
 *			will be changed to use a renderer with a orthographic projection
 *			that is drawn to the screen infront of everything else (setting depth buffer)
 *			hence the seperate class without inheriting or anything like that
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class GameHUD
{
public:

	/**
	 * @fn	GameHUD::GameHUD(const int width, const int height);
	 *
	 * @brief	Constructor which takes window width and height
	 * 			to set the position of the text
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	width 	The width.
	 * @param	height	The height.
	 */

	GameHUD(const int width, const int height);
	~GameHUD();

	/**
	 * @fn	void GameHUD::Update(const PlayerGameObject& player, const float& timer);
	 *
	 * @brief	Updates this objects text given by player score and timer
	 * 			Player is passed incase more is to be displayed
	 * 			otherwise could just pass the score
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	player	The player character in the game
	 * @param	timer 	The timer - time left in this round
	 */

	void Update(const PlayerGameObject& player, const float& timer);

	/**
	 * @fn	void GameHUD::Draw(sf::RenderWindow* window);
	 *
	 * @brief	Draws the text to the window
	 * 			Needs the window to call draw
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	window	If non-null, the window.
	 */

	void Draw(sf::RenderWindow* window);

private:

	std::string scoreInfo;
	std::string timerInfo;
	sf::Text scoreText;
	sf::Text timerText;
	sf::Font font;
};

