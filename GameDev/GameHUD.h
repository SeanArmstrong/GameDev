#pragma once
#include <string>
#include "PlayerGameObject.h"
#include <SFML/Graphics.hpp>

/* At the moment this is almost identical to DebugHUD however this
	will be changed to use a renderer with a orthographic projection
	that is drawn to the screen infront of everything else (setting depth buffer)
	hence the seperate class without inheriting or anything like that
*/
class GameHUD
{
public:
	GameHUD(const int width, const int height);
	~GameHUD();

	void Update(const PlayerGameObject& player, const float& timer);
	void Draw(sf::RenderWindow* window);

private:

	std::string scoreInfo;
	std::string timerInfo;
	sf::Text scoreText;
	sf::Text timerText;
	sf::Font font;
};

