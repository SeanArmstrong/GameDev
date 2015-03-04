#include "GameHUD.h"

GameHUD::GameHUD(const int width, const int height){
	font.loadFromFile("assets/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(sf::Vector2f(5, height - 25));
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Regular);
}


GameHUD::~GameHUD(){

}

void GameHUD::Update(const PlayerGameObject& player){
	info = "Score: " + std::to_string(player.getScore());
}

void GameHUD::Draw(sf::RenderWindow* window){
	text.setString(info);
	window->pushGLStates();
	window->draw(text);
	window->popGLStates();
}
