#pragma once
#include <string>
#include "PlayerGameObject.h"
#include <SFML/Graphics.hpp>

class MultiPlayerGameHUD
{
public:
	MultiPlayerGameHUD(const int width, const int height);
	~MultiPlayerGameHUD();
	void Update(const std::vector<PlayerGameObject*> players, const float& timer);
	void Draw(sf::RenderWindow* window);

private:

	std::string scoreInfo;
	std::string timerInfo;
	sf::Text scoreText;
	sf::Text timerText;
	sf::Font font;
};

