#include "ControlHUD.h"


ControlHUD::ControlHUD(const int width, const int height, const int xPos, const int yPos){
	font.loadFromFile("assets/fonts/arial.ttf");

	controlText.setFont(font);
	controlText.setCharacterSize(15);
	controlText.setPosition(sf::Vector2f(xPos, yPos));
	controlText.setColor(sf::Color::White);
	controlText.setStyle(sf::Text::Regular);
}


ControlHUD::~ControlHUD(){
}

void ControlHUD::SetControlText(const std::string text){
	controlText.setString(text);
}

void ControlHUD::Draw(sf::RenderWindow* window){
	window->pushGLStates();
	window->draw(controlText);
	window->popGLStates();
}