#pragma once
#include "State.h"
#include "RenderObject.h"
#include "ResourceManager.h"
#include "GameState.h"


class MainMenuState : public State
{
public:
	MainMenuState(sf::RenderWindow* w);
	virtual ~MainMenuState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();

protected:

private:

	RenderObject* title;

};
