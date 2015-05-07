#pragma once
#include "State.h"
#include "MainMenuState.h"

/**
* @class	EndGameState
*
* @brief	Occurs for multiplayer games with a given text result
*			
* @author	Sean Armstrong
* @date	08/03/2015
*/
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
	virtual std::string getControlText() const;

private:

	RenderObject* title;

	std::string messageString;
	sf::Text messageText;
	sf::Font font;
};

