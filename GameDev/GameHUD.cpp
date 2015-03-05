#include "GameHUD.h"

GameHUD::GameHUD(const int width, const int height){
	font.loadFromFile("assets/fonts/arial.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setPosition(sf::Vector2f(5, height - 25));
	scoreText.setColor(sf::Color::White);
	scoreText.setStyle(sf::Text::Regular);

	timerText.setFont(font);
	timerText.setCharacterSize(20);
	timerText.setPosition(sf::Vector2f(width - 40, 5));
	timerText.setColor(sf::Color::White);
	timerText.setStyle(sf::Text::Regular);
}


GameHUD::~GameHUD(){

}

void GameHUD::Update(const PlayerGameObject& player, const float& timer){
	scoreInfo = "Score: " + std::to_string(player.getScore());
	timerInfo = std::to_string(timer);
}

void GameHUD::Draw(sf::RenderWindow* window){
	scoreText.setString(scoreInfo);
	timerText.setString(timerInfo);

	window->pushGLStates();
	window->draw(scoreText);
	window->draw(timerText);
	window->popGLStates();
}
