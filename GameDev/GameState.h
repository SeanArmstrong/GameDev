#pragma once
#include "State.h"
#include "Singleton.h"
#include "ResourceManager.h"


class GameState : public State
{
public:
	GameState();
	~GameState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(sf::Event event);
	virtual void Update();
	virtual void Render();

protected:


private:

	RenderObject o;
};

