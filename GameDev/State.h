#pragma once

#include "CoreEngine.h"
#include "SFMLRenderer.h"

class CoreEngine;

class State
{
public:
	State(const float& width, const float& height) : screenWidth(width), screenHeight(height){};

	virtual void Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(CoreEngine& engine, sf::Event event) = 0;
	virtual void Update(CoreEngine& engine) = 0;
	virtual void Render() = 0;

	void ChangeState(CoreEngine* engine, State* state);
	bool isPaused(){ return paused; }

protected: 
	SFMLRenderer renderer; // Should this be here?
	bool paused;

	const float screenWidth;
	const float screenHeight;

};

