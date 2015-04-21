#include "GameState.h"

GameState::GameState(sf::RenderWindow* w) : State(w){
	level = new Level1(w, &renderer);
}


GameState::~GameState(){
	delete level;
}


void GameState::Initialise(){}

void GameState::Pause(){
	paused = !paused;
}

void GameState::Resume(){}


void GameState::Update(CoreEngine& engine){
	level->Update(engine);
}

void GameState::Render(){
	level->Render();
}


void GameState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.key.code == sf::Keyboard::Escape){
		engine.ChangeState(new MainMenuState(window));
	}
}

/*void GameState::resetScene(){
	delete player;
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete worldObjects[i];
	}

	loadScene();
}*/