#pragma once
#include "State.h"
#include "ResourceManager.h"
#include "MainMenuState.h"
#pragma once

class LevelWonState : public State
{
public:
	LevelWonState(sf::RenderWindow* w);
	~LevelWonState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();

private:

	RenderObject* title;
};

