#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#define PAUSED_MENU_ITEMS 2

class PauseHUD
{
public:
	PauseHUD(const int width, const int height);
	~PauseHUD();

	void Update();

	void Draw(sf::RenderWindow* window);

	void MoveUp();
	void MoveDown();

	int GetElementIndex();

private:

	sf::Font font;
	sf::Text menu[PAUSED_MENU_ITEMS];
	sf::Text title;
	int selectedItemIndex;
};

