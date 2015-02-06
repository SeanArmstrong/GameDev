#pragma once

#include "Game.h"
#include "State.h"

Game::Game() : screenHeight(800), screenWidth(600) {
}

Game::~Game(){}

void Game::run(){
	Initialise();
	gameLoop();
}

void Game::Initialise(){
	window.create(sf::VideoMode(screenWidth, screenHeight), "Game");
	//window.setFramerateLimit(60);

	if (glewInit() != GLEW_OK) {
		std::cout << "Cannot initialise GLEW!" << std::endl;
		return;
	}
	running = true;
}


void Game::gameLoop(){
	while (running){
		processInput();
		Draw();
	}
}
void Game::processInput(){
	sf::Event event;
	while (window.pollEvent(event)){
		switch(event.type){
		case sf::Event::Closed:
			running = false;
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code){
			case sf::Keyboard::Escape:
				running = false;
				break;
			}
			break;

		case sf::Event::MouseMoved:
			std::cout << "x: " << event.mouseMove.x << "  y: " << event.mouseMove.y << std::endl;
		}
	}
}

void Game::Cleanup(){
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
}

void Game::HandleEvents(){
	states.back()->HandleEvents(this);
}

void Game::Update(){
	states.back()->Update(this);
}

void Game::Draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	//states.back()->Draw(this);
	// Draw

	window.display();
}





// State Stuff


void Game::ChangeState(State* state){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void Game::PushState(State* state){
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void Game::PopState(){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
}