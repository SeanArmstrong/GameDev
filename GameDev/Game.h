#pragma once
#include "RenderObject.h"
#include "SFMLRenderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include "Matrix3.h"
#include "Matrix4.h"
#include "State.h"
#include <vector>

class State;

class Game
{
public:
	Game();
	~Game();

	void run();
	void Cleanup();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();

	void HandleEvents(sf::Event event);
	void Update();
	void Render();

	bool Running() { return running; }
	void Quit() { running = false; }

private:

	// TEMP STUFF
	RenderObject o;
	Mesh*	m;
	Shader* s;
	SFMLRenderer r;
	// END OF TEMP



	void Initialise();

	void gameLoop();
	void processInput();

	sf::RenderWindow window;
	std::vector<State*> states;

	int screenWidth;
	int screenHeight;

	bool running;
};

