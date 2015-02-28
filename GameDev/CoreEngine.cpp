#pragma once

#include "CoreEngine.h"
#include "State.h"
#include "GameState.h"

CoreEngine::CoreEngine(const int width, const int height, const float framerate) :
			screenHeight(height), screenWidth(width), framerate(framerate) {
}

CoreEngine::~CoreEngine(){}

void CoreEngine::run(){
	if (!running){
		Initialise();
		states.push_back(new GameState());
		gameLoop();
	}
}

void CoreEngine::Initialise(){
	window.create(sf::VideoMode(screenWidth, screenHeight), "Game");
	//window.setFramerateLimit(60);

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

	const float frameTime = 1.0 / framerate;

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


			// End of timer stuff
			// Start of update/render
			processInput();


			Update(frameTime);

			clearScreen();

			Render(frameTime);

			window.display();
			frames++;
		}
	}
}
void CoreEngine::processInput(){
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed || (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
			running = false;
		}
		else if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1){
			states.front()->Pause();
		}
		else{
			HandleEvents(event);
		}
	}
}

void CoreEngine::Cleanup(){
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
	window.close();
}

void CoreEngine::HandleEvents(sf::Event event){
	states.front()->HandleEvents(event, window);
}

void CoreEngine::Update(const float& msec){
	states.front()->Update();
}

void CoreEngine::Render(const float& msec){
	states.front()->Render();
}


// State Stuff


void CoreEngine::ChangeState(State* state){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void CoreEngine::PushState(State* state){
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Initialise();
}

void CoreEngine::PopState(){
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
}

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