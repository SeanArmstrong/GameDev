#pragma once

#include "Game.h"
#include "State.h"

Game::Game() : screenHeight(600), screenWidth(800) {

}

Game::~Game(){}

void Game::run(){
	Initialise();

	r = SFMLRenderer();
	m = Mesh::LoadMeshFile("cube.asciimesh");
	//m = Mesh::LoadMeshObj("assets/models/cube.obj");
	//m = Mesh::LoadMeshObj("assets/models/sphere.obj");
	s = new Shader("assets/shaders/basicvert.glsl", "assets/shaders/textureFrag.glsl");
	o = RenderObject(m, s);
	o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
	r.AddRenderObject(o);
	r.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	r.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));


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
		o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Rotation(0.005f, Vector3(1, 0, 1)));
		processInput();
		r.UpdateScene(1.0);
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
	//window.clear(sf::Color(255, 0, 0, 255));
	//window.pushGLStates();

	//states.back()->Draw(this);
	// Draw
	r.RenderScene();
	//window.popGLStates();
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