#pragma once
#include "GameEngine.h"
#include "State.h"

GameEngine::GameEngine(){}
GameEngine::~GameEngine(){}

void GameEngine::Initialise(){
	// TODO: This
}

void GameEngine::Cleanup(){
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
}

void GameEngine::ChangeState(State* state){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void GameEngine::PushState(State* state){
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void GameEngine::PopState(){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents(){
	states.back()->HandleEvents(this);
}

void GameEngine::Update(){
	states.back()->Update(this);
}

void GameEngine::Draw(){
	states.back()->Draw(this);
}