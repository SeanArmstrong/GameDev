#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class	DebugHUD
 *
 * @brief	A debug hud that shows FPS in the top right
 * 			uses SFML draw functionality
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class DebugHUD
{
public:

	/**
	 * @fn	DebugHUD::DebugHUD();
	 *
	 * @brief	Loads in font and sets text properties
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	DebugHUD();
	~DebugHUD();

	/**
	 * @fn	void DebugHUD::Update(const float& frames);
	 *
	 * @brief	Updates the text to the given framerate
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	frames	framerate to display
	 */

	void Update(const float& frames);

	/**
	 * @fn	void DebugHUD::Draw(sf::RenderWindow& window);
	 *
	 * @brief	Draws the text to the given window
	 * 			uses glpush and gl pop states to save
	 * 			and restore open gl state before and after
	 * 			drawing
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	window	the current rendering window
	 */

	void Draw(sf::RenderWindow& window);

private:

	std::string info;
	sf::Text text;
	sf::Font font;
};

