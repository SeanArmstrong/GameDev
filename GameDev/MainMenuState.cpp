#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* w) : State(w){
	Initialise();
}

MainMenuState::~MainMenuState(){

}

void MainMenuState::Initialise(){
	font.loadFromFile("assets/fonts/arial.ttf");
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Level1");
	menu[0].setPosition((float) window->getSize().x / 2.0f, (float) window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + 1) * 1);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Level2");
	menu[1].setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y / (float) (MAX_NUMBER_OF_ITEMS + 1) * 2);

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Pool Level");
	menu[2].setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y / (float)(MAX_NUMBER_OF_ITEMS + 1) * 3);

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y / (float) (MAX_NUMBER_OF_ITEMS + 1) * 4);

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
				engine.Quit();
				break;
			}
		}
	}
}