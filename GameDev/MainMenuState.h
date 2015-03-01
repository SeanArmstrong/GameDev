#pragma once
#include "State.h"
#include "RenderObject.h"
#include "ResourceManager.h"
#include "GameState.h"


class MainMenuState : public State
{
public:
	MainMenuState(const float& width, const float& height);
	virtual ~MainMenuState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update();
	virtual void Render();

protected:

private:

	RenderObject* title;

};
