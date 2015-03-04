#pragma once
#include <SFML/Graphics.hpp>

class DebugHUD
{
public:
	DebugHUD();
	~DebugHUD();

	void Update(const float& frames);
	void Draw(sf::RenderWindow& window);

private:

	std::string info;
	sf::Text text;
	sf::Font font;
};

