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
#include "GameTimer.h"
#include "RenderUtils.h"
#include "DebugHUD.h"

class State;

class CoreEngine
{
public:
	CoreEngine(const int width, const int height, const float framerate);
	~CoreEngine();

	void run();
	void Cleanup();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();

	void HandleEvents(sf::Event event);
	void Update(const float& msec);
	void Render(const float& msec);

	bool Running() { return running; }
	void Quit() { running = false; }

	sf::RenderWindow* getWindow();

private:
	void Initialise();
	void gameLoop();
	void processInput();

	sf::RenderWindow window;
	std::vector<State*> states;

	int screenWidth;
	int screenHeight;
	float framerate;

	bool running;
	bool polygons;
	bool showDebugInfo;

	DebugHUD debugInfo;
	
};

