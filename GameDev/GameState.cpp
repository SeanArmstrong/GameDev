#include "GameState.h"

GameState::GameState(sf::RenderWindow* w, const int l) : State(w){
	switch (l){
	case 1:
		level = new Level1(w, &renderer);
		break;
	case 2:
		level = new Level2(w, &renderer);
		break;
	case 3: 
		level = new PoolLevel(w, &renderer);
		break;
	case 4:
		level = new MultiplayerPoolLevel(w, &renderer);
		break;
	default:
		level = new Level1(w, &renderer);
		break;
	}
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
		LevelLost(engine, level->getEndOfLevelMessage());
	}
	else if (level->isGameWon()){
		LevelWon(engine, level->getEndOfLevelMessage());
	}
	else if (level->isGameFinished()){
		LevelFinished(engine, level->getEndOfLevelMessage());
	}
	else if (level->isGameQuitting()){
		QuitLevel(engine);
	}
}

void GameState::Render(){
	level->Render();
}


void GameState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyReleased){
		if (event.key.code == sf::Keyboard::Return){
			if (level->isGamePaused()){
				std::cout << "Resume" << std::endl;
				level->Resume();
			}
		}
		if (event.key.code == sf::Keyboard::Escape){
			std::cout << "Pause" << std::endl;
			level->Pause();
		}
	}
}

void GameState::LevelLost(CoreEngine& engine, std::string message){
	InputManager::ResetInstance();
	engine.ChangeState(new LevelLostState(window, message));
}

void GameState::LevelWon(CoreEngine& engine, std::string message){
	InputManager::ResetInstance();
	engine.ChangeState(new LevelWonState(window, message));
}

void GameState::LevelFinished(CoreEngine& engine, std::string message){
	InputManager::ResetInstance();
	engine.ChangeState(new EndGameState(window, message));
}

void GameState::QuitLevel(CoreEngine& engine){
	InputManager::ResetInstance();
	ResourceManager::ResetInstance();
	engine.ChangeState(new MainMenuState(window));
}

std::string GameState::getControlText() const{
	return level->getControlText();
}