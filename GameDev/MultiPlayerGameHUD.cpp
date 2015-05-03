#include "MultiPlayerGameHUD.h"


MultiPlayerGameHUD::MultiPlayerGameHUD(const int width, const int height){
	font.loadFromFile("assets/fonts/arial.ttf");

	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setPosition(sf::Vector2f(5.0f, (float)height - (25.0f)));
	scoreText.setColor(sf::Color::White);
	scoreText.setStyle(sf::Text::Regular);

	timerText.setFont(font);
	timerText.setCharacterSize(20);
	timerText.setPosition(sf::Vector2f((float)width - 60.0f, 5.0f));
	timerText.setColor(sf::Color::White);
	timerText.setStyle(sf::Text::Regular);
}


MultiPlayerGameHUD::~MultiPlayerGameHUD()
{
}

void MultiPlayerGameHUD::Update(const std::vector<PlayerGameObject*> players, const float& timer){
	std::string scoreString = "";
	for (unsigned int i = 0; i < players.size(); i++){
		scoreString += "Player " + std::to_string(i + 1) + ": " + std::to_string(players[i]->getScore());
	}
	
	scoreInfo = scoreString;
	timerInfo = std::to_string(timer);
}

void MultiPlayerGameHUD::Draw(sf::RenderWindow* window){
	scoreText.setString(scoreInfo);
	timerText.setString(timerInfo);

	window->pushGLStates();
	window->draw(scoreText);
	window->draw(timerText);
	window->popGLStates();
}