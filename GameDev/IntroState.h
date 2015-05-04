#pragma once
#include "State.h"
#include "RenderObject.h"
#include "ResourceManager.h"
#include "MainMenuState.h"

/**
 * @class	IntroState
 *
 * @brief	A splash screen state for the game
 * 			first screen you see
 * 			progresses to menu screen
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

class IntroState : public State
{
public:
	IntroState(sf::RenderWindow* w);
	virtual ~IntroState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();
	virtual std::string getControlText() const;

protected:

private:

	RenderObject* title;

};

