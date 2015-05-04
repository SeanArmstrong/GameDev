#pragma once

#include "CoreEngine.h"
#include "State.h"
#include "GameState.h"
#include "IntroState.h"

CoreEngine::CoreEngine(const int width, const int height, const float framerate) :
			screenHeight(height), screenWidth(width), framerate(framerate), controlInfo(width, height) {
}

CoreEngine::~CoreEngine(){
	Cleanup();
}

void CoreEngine::run(){
	if (!running){
		Initialise();
		states.push_back(new IntroState(&window));
		controlInfo.SetControlText(states.back()->getControlText());
		gameLoop();
	}
	ResourceManager::ResetInstance();
	Cleanup();
}

void CoreEngine::Initialise(){
	window.create(sf::VideoMode(screenWidth, screenHeight), "Game");

	if (glewInit() != GLEW_OK) {
		std::cout << "Cannot initialise GLEW!" << std::endl;
		return;
	}
	getOpenGLVersion();

	initOpenGlStates();
	running = true;
}


void CoreEngine::gameLoop(){
	int frames = 0;
	float frameCounter = 0;

	const float frameTime = 1.0f / framerate;

	float lastTime = GameTimer::getTime();
	float unprocessedTime = 0;

	while (running){

		float startTime = GameTimer::getTime();
		float passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime / 1000.0f;
		frameCounter += passedTime;

		while (unprocessedTime > frameTime){
			if (frameCounter >= 1000.0f){
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}
			unprocessedTime -= frameTime;
			GameTimer::setDelta(frameTime);

			processInput();

			if (polygons){
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			Update(frameTime);

			clearScreen();

			Render(frameTime);

			if (showDebugInfo){
				debugInfo.Update((frames / frameCounter) * 1000);
				debugInfo.Draw(window);
			}
			if (showControls){
				controlInfo.Draw(&window);
			}

			window.display();
			frames++;
		}
	}
}

void CoreEngine::processInput(){
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed){
			running = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
			showDebugInfo = !showDebugInfo;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)){
			polygons = !polygons;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)){
			showControls = !showControls;
		}
		else if (event.type == sf::Event::Resized){
			glViewport(0, 0, event.size.width, event.size.height);
		}

		HandleEvents(event);
	}
}

void CoreEngine::Cleanup(){
	while (!states.empty()) {
		delete states.back();
		states.pop_back();
	}
	window.close();
}

void CoreEngine::HandleEvents(sf::Event event){
	states.front()->HandleEvents(*this, event);
}

void CoreEngine::Update(const float& msec){
	states.front()->Update(*this);
}

void CoreEngine::Render(const float& msec){
	states.front()->Render();
}

sf::RenderWindow* CoreEngine::getWindow(){
	return &window;
}


// State Stuff
void CoreEngine::ChangeState(State* state){
	if (!states.empty()) {
		delete states.back();
		states.pop_back();
	}
	states.push_back(state);
	setChangeStateInfo();
}

void CoreEngine::PushState(State* state){
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Initialise();
	setChangeStateInfo();
}

void CoreEngine::PopState(){
	if (!states.empty()) {
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
	setChangeStateInfo();
}

void CoreEngine::setChangeStateInfo(){
	showDebugInfo = false;
	controlInfo.SetControlText(states.back()->getControlText());
}