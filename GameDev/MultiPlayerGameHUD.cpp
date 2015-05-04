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

	lifeText.setFont(font);
	lifeText.setCharacterSize(20);
	lifeText.setPosition(sf::Vector2f(5.0f, (float)height - (50.0f)));
	lifeText.setColor(sf::Color::White);
	lifeText.setStyle(sf::Text::Regular);
}


MultiPlayerGameHUD::~MultiPlayerGameHUD()
{
}

void MultiPlayerGameHUD::Update(const std::vector<PlayerGameObject*> players, const float& timer, const bool showLives){
	std::string scoreString = "Scores [ ";
	for (unsigned int i = 0; i < players.size(); i++){
		scoreString += "Player " + std::to_string(i + 1) + ": " + std::to_string(players[i]->getScore()) + "  ";
	}
	scoreString += "]";

	std::string lifeString = "";

	if (showLives){
		lifeString = "Lives    [ ";
		for (unsigned int i = 0; i < players.size(); i++){
			lifeString += "Player " + std::to_string(i + 1) + ": " + std::to_string(players[i]->getPlayerLives()) + "  ";
		}
		lifeString += "]";
	}
	
	lifeInfo = lifeString;
	scoreInfo = scoreString;
	timerInfo = std::to_string(timer);
}

void MultiPlayerGameHUD::Draw(sf::RenderWindow* window){
	scoreText.setString(scoreInfo);
	timerText.setString(timerInfo);
	lifeText.setString(lifeInfo);

	window->pushGLStates();
	window->draw(scoreText);
	window->draw(timerText);
	window->draw(lifeText);
	window->popGLStates();
}