#include "GameState.h"

GameState::GameState(sf::RenderWindow* w) : State(w){
	level = new Level2(w, &renderer);
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
	level->Update();
	if (level->isGameLost()){
		LevelLost(engine);
	}
	else if (level->isGameWon()){
		LevelWon(engine);
	}
}

void GameState::Render(){
	level->Render();
}


void GameState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.key.code == sf::Keyboard::Escape){
		engine.ChangeState(new MainMenuState(window));
	}
}
void GameState::LevelLost(CoreEngine& engine){
	engine.ChangeState(new LevelLostState(window));
}

void GameState::LevelWon(CoreEngine& engine){
	engine.ChangeState(new LevelWonState(window));
}