#include "PauseHUD.h"


PauseHUD::PauseHUD(const int width, const int height){
	font.loadFromFile("assets/fonts/arial.ttf");

	title.setFont(font);
	title.setColor(sf::Color::Blue);
	title.setPosition((float)width / 2.0f - 50, (float)height / (float)(PAUSED_MENU_ITEMS + 2) * 1);
	title.setString("Paused");

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Resume");
	menu[0].setPosition((float)width / 2.0f - 50, (float)height / (float)(PAUSED_MENU_ITEMS + 2) * 2);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition((float)width / 2.0f - 50, (float)height / (float)(PAUSED_MENU_ITEMS + 2) * 3);

	selectedItemIndex = 0;
}

PauseHUD::~PauseHUD(){
}

void PauseHUD::Update(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		MoveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		MoveDown();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		switch (selectedItemIndex){
		case 0:
			// Hmm 
			break;
		case 1:
			// Hmm
			break;
		}
	}
}

void PauseHUD::MoveUp(){
	menu[1].setColor(sf::Color::White);
	selectedItemIndex = 0;
	menu[0].setColor(sf::Color::Red);
}

void PauseHUD::MoveDown(){
	menu[0].setColor(sf::Color::White);
	selectedItemIndex = 1;
	menu[1].setColor(sf::Color::Red);
}

void PauseHUD::Draw(sf::RenderWindow* window){
	window->pushGLStates();
	window->draw(menu[0]);
	window->draw(menu[1]);
	window->draw(title);
	window->popGLStates();
}

int PauseHUD::GetElementIndex(){
	return selectedItemIndex;
}