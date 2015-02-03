#pragma once

#include "Game.h"
class Game;

class State
{
public:

	virtual void Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(Game* game) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Draw(Game* game) = 0;

	void ChangeState(Game* game, Game* state);

protected: 
	State() { }
};

