#pragma once

#include "CoreEngine.h"
#include "SFMLRenderer.h"
#include <SFML\Window.hpp>

class CoreEngine;

class State
{
public:
	State(sf::RenderWindow* w) : window(w) {};

	virtual void Initialise() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(CoreEngine& engine, sf::Event event) = 0;
	virtual void Update(CoreEngine& engine) = 0;
	virtual void Render() = 0;

	void ChangeState(CoreEngine* engine, State* state);
	bool isPaused(){ return paused; }

protected: 
	sf::RenderWindow* window;
	SFMLRenderer renderer; // Should this be here?
	bool paused;
};

