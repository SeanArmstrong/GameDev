#include "GameHUD.h"

GameHUD::GameHUD(const int width, const int height){
	font.loadFromFile("assets/fonts/arial.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setPosition(sf::Vector2f(5.0f, (float)height - 25.0f));
	scoreText.setColor(sf::Color::White);
	scoreText.setStyle(sf::Text::Regular);

	timerText.setFont(font);
	timerText.setCharacterSize(20);
	timerText.setPosition(sf::Vector2f((float)width - 60.0f, 5.0f));
	timerText.setColor(sf::Color::White);
	timerText.setStyle(sf::Text::Regular);

	lifeText.setFont(font);
	lifeText.setCharacterSize(20);
	lifeText.setPosition(sf::Vector2f(5.0f, (float)height - 50.0f));
	lifeText.setColor(sf::Color::White);
	lifeText.setStyle(sf::Text::Regular);
}


GameHUD::~GameHUD(){

}

void GameHUD::Update(const PlayerGameObject& player, const float& timer){
	scoreInfo = "Score: " + std::to_string(player.getScore());
	livesInfo = "Lives: " + std::to_string(player.getPlayerLives());
	timerInfo = std::to_string(timer);
}

void GameHUD::Draw(sf::RenderWindow* window){
	scoreText.setString(scoreInfo);
	timerText.setString(timerInfo);
	lifeText.setString(livesInfo);

	window->pushGLStates();
	window->draw(scoreText);
	window->draw(timerText);
	window->draw(lifeText);
	window->popGLStates();
}
