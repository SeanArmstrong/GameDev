#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* w) : State(w){
	Initialise();
}

MainMenuState::~MainMenuState(){

}

void MainMenuState::Initialise(){
	font.loadFromFile("assets/fonts/arial.ttf");

	nonSelectMenu[0].setFont(font);
	nonSelectMenu[0].setColor(sf::Color::Blue);
	nonSelectMenu[0].setString("Single Player");
	nonSelectMenu[0].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 1);

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Level1");
	menu[0].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 2);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Level2");
	menu[1].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 3);

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Pool Level");
	menu[2].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 4);

	nonSelectMenu[1].setFont(font);
	nonSelectMenu[1].setColor(sf::Color::Blue);
	nonSelectMenu[1].setString("Multiplayer");
	nonSelectMenu[1].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 5);

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("2 Player Pool");
	menu[3].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 6);

	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition((float)window->getSize().x / 2.0f - 50, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + NON_SELECTABLE_ITEMS + 1) * 7);

	selectedItemIndex = 0;
}

void MainMenuState::Pause(){

}

void MainMenuState::Resume(){

}

void MainMenuState::Update(CoreEngine& engine){
}

void MainMenuState::MoveUp(){
	menu[selectedItemIndex].setColor(sf::Color::White);
	selectedItemIndex--;
	if (selectedItemIndex < 0){
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
	}
	menu[selectedItemIndex].setColor(sf::Color::Red);
}

void MainMenuState::MoveDown(){
	menu[selectedItemIndex].setColor(sf::Color::White);
	selectedItemIndex = (selectedItemIndex + 1) % MAX_NUMBER_OF_ITEMS;
	menu[selectedItemIndex].setColor(sf::Color::Red);
}

void MainMenuState::Render(){
	window->pushGLStates();
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window->draw(menu[i]);
	}
	for (int i = 0; i < NON_SELECTABLE_ITEMS; i++){
		window->draw(nonSelectMenu[i]);
	}
	window->popGLStates();
}

void MainMenuState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyReleased){
		if (event.key.code == sf::Keyboard::Up){
			MoveUp();
		}
		else if (event.key.code == sf::Keyboard::Down){
			MoveDown();
		}
		else if (event.key.code == sf::Keyboard::Return){
			ResourceManager::ResetInstance();
			switch (selectedItemIndex){
			case 0:
				engine.ChangeState(new GameState(window, 1));
				break;
			case 1:
				engine.ChangeState(new GameState(window, 2));
				break;
			case 2:
				engine.ChangeState(new GameState(window, 3));
				break;
			case 3:
				engine.ChangeState(new GameState(window, 4));
				break;
			default: 
				engine.Quit();
			}
		}
	}
}