#pragma once
#include <string>
#include <SFML/Graphics.hpp>

/**
* @class	ControlHUD
*
* @brief	HUD for user controls to be displayed on each page.
*			The x and y position of this control hud can be set 
*			on initialisation
*
* @author	Sean Armstrong
* @date	07/05/2015
*/

class ControlHUD
{
public:
	/**
	* @fn	ControlHUD(const int width, const int height, const int xPos, const int yPos);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	width	 	The width of the window.
	* @param	height   	The height of the window.
	* @param	xPos		X Position of the HUD
	* @param	yPos		Y Position of the HUD
	*/
	ControlHUD(const int width, const int height, const int xPos, const int yPos);
	~ControlHUD();

	/**
	* @fn	SetControlText(const std::string text);
	*
	* @brief	Sets the text for the control helper.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	text	 Text to be displayed.
	*/
	void SetControlText(const std::string text);

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

	sf::Text controlText;
	sf::Font font;
};

