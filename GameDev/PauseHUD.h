#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#define PAUSED_MENU_ITEMS 2

/**
* @class	PauseHUD
*
* @brief	HUD that appears when a level is paused
*			Contains a resume and a exit button
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PauseHUD
{
public:

	/**
	* @fn	PauseHUD(const int width, const int height);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	width	 	The width of the window.
	* @param	height   	The height of the window.

	*/
	PauseHUD(const int width, const int height);
	~PauseHUD();

	/**
	* @fn	Update(const std::vector<PlayerGameObject*> players, const float& timer, const bool showLives = false);
	*
	* @brief	Checks for up and down key enter and moves changes the selected element
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void Update();

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

	/**
	* @fn	void MoveUp();
	*
	* @brief	moves the selected item up
	* 			
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void MoveUp();

	/**
	* @fn	void MoveDown();
	*
	* @brief	moves the selected item down
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void MoveDown();

	/**
	* @fn	int GetElementIndex();
	*
	* @brief	gets the currently selected index item
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	int GetElementIndex();

private:

	sf::Font font;
	sf::Text menu[PAUSED_MENU_ITEMS];
	sf::Text title;
	int selectedItemIndex;
};

