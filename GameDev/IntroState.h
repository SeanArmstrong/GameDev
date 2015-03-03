#pragma once
#include "State.h"
#include "RenderObject.h"
#include "ResourceManager.h"
#include "MainMenuState.h"


class IntroState : public State
{
public:
	IntroState(const int width, const int height);
	virtual ~IntroState();

	virtual void Initialise();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();

protected:

private:

	RenderObject* title;

};

