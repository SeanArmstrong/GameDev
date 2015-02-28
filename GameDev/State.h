#pragma once

#include "CoreEngine.h"
#include "SFMLRenderer.h"
class CoreEngine;

class State
{
public:

	virtual void Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(sf::Event event, const sf::RenderWindow& window) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	void ChangeState(CoreEngine* engine, State* state);
	bool isPaused(){ return paused; }

protected: 
	State() { }
	SFMLRenderer renderer; // Should this be here?
	bool paused;

};

