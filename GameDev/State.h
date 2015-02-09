#pragma once

#include "Game.h"
#include "SFMLRenderer.h"
class Game;

class State
{
public:

	virtual void Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(sf::Event event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	void ChangeState(Game* game, Game* state);

protected: 
	State() { }
	SFMLRenderer renderer;

};

