#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class ControlHUD
{
public:
	ControlHUD(const int width, const int height);
	~ControlHUD();

	void SetControlText(const std::string text);

	void Draw(sf::RenderWindow* window);

private:

	sf::Text controlText;
	sf::Font font;
};

