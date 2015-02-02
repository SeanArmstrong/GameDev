#pragma once

#include "GameEngine.h"
class GameEngine;

class State
{
public:

	virtual void Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Update(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;

	void ChangeState(GameEngine* game, State* state);

protected: 
	State() { }
};

