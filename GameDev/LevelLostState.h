#pragma once
#include "State.h"
#include "ResourceManager.h"
#include "MainMenuState.h"
#pragma once

/**
 * @class	LevelLostState
 *
 * @brief	Occurs when the user wins a level
 *			currently just displays a box that states 
 * 			that you lost. 
 * 			Press any key to continue
 * 
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

class LevelLostState : public State
{
public:
	LevelLostState(sf::RenderWindow* w);
	~LevelLostState();

	virtual void Initialise();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);
	virtual void Update(CoreEngine& engine);
	virtual void Render();

private:

	RenderObject* title;
};

