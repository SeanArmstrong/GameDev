#pragma once

#include "Game.h"
#include "State.h"
#include "GameState.h"

Game::Game() : screenHeight(600), screenWidth(800) {
}

Game::~Game(){}

void Game::run(){
	Initialise();

	/*r = SFMLRenderer();
	//m = Mesh::LoadMeshFile("cube.asciimesh");
	//m = Mesh::LoadMeshObj("assets/models/cube.obj");
	m = Mesh::LoadMeshObj("assets/models/sphere.obj");
	s = new Shader("assets/shaders/basicvert.glsl", "assets/shaders/textureFrag.glsl");

	if (s->UsingDefaultShader()) {
		cout << "Warning: Using default shader! Your shader probably hasn't worked..." << endl;
		cout << "Press any key to continue." << endl;
		std::cin.get();
	}

	o.Intialize(m, s);

	o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
	r.AddRenderObject(o);

	r.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	r.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
	*/

	states.push_back(new GameState());
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
	sf::Clock clock;

	while (running){
		sf::Int32 elapsed1 = clock.getElapsedTime().asMilliseconds();
		processInput();

		Update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Render();
		window.display();
	}
}
void Game::processInput(){
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed || (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
			running = false;
		}
		else{
			HandleEvents(event);
		}
	}
}

void Game::Cleanup(){
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
}

void Game::HandleEvents(sf::Event event){
	states.front()->HandleEvents(event);
}

void Game::Update(){
	states.front()->Update();
}

void Game::Render(){
	states.front()->Render();
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