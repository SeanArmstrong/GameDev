#pragma once
#include "State.h"
#include "MainMenuState.h"

class EndGameState : public State
{
public:
	EndGameState(sf::RenderWindow* w, const std::string message);
	virtual ~EndGameState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();

private:

	RenderObject* title;

	std::string messageString;
	sf::Text messageText;
	sf::Font font;
};

