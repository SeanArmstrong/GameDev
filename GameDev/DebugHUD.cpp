#include "DebugHUD.h"
#include <GL\glew.h>

DebugHUD::DebugHUD(){
	font.loadFromFile("assets/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Regular);
}


DebugHUD::~DebugHUD(){
}

void DebugHUD::Update(const float& frames){
	info = "FPS: " + std::to_string(frames);
}

void DebugHUD::Draw(sf::RenderWindow& window){
	text.setString(info);
	window.pushGLStates();
	window.draw(text);
	window.popGLStates();
}
