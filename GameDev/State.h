#pragma once

#include "CoreEngine.h"
#include "SFMLRenderer.h"
#include <SFML\Window.hpp>

class CoreEngine;

/**
 * @class	State
 *
 * @brief	Pure Abstract class for all engine states
 * 			to inherit. Contains methods that all
 * 			states must implement
 * 			
 * 			Initialise
 * 			Pause
 * 			Resume
 * 			HandleEvents
 * 			Update
 * 			Render
 * 			
 * 			Also handles changin of state
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class State
{
public:

	/**
	 * @fn	State::State(sf::RenderWindow* w)
	 *
	 * @brief	Constructor takes in a render window which all states must
	 * 			pass from their constructors
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	w	If non-null, the sf::RenderWindow* to process.
	 */

	State(sf::RenderWindow* w) : window(w) {};

	/**
	 * @fn	virtual void State::Initialise() = 0;
	 *
	 * @brief	Initialises the state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void Initialise() = 0;

	/**
	 * @fn	virtual void State::Pause() = 0;
	 *
	 * @brief	Pauses the current state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void Pause() = 0;

	/**
	 * @fn	virtual void State::Resume() = 0;
	 *
	 * @brief	Resumes the current state from pause
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void Resume() = 0;

	/**
	 * @fn	virtual void State::HandleEvents(CoreEngine& engine, sf::Event event) = 0;
	 *
	 * @brief	Handles the events generally to move between states
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 * @param	event		  	The event.
	 */

	virtual void HandleEvents(CoreEngine& engine, sf::Event event) = 0;

	/**
	 * @fn	virtual void State::Update(CoreEngine& engine) = 0;
	 *
	 * @brief	Updates call for given state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 */

	virtual void Update(CoreEngine& engine) = 0;

	/**
	 * @fn	virtual void State::Render() = 0;
	 *
	 * @brief	Renders or draw of current state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void Render() = 0;

	/**
	 * @fn	void State::ChangeState(CoreEngine* engine, State* state);
	 *
	 * @brief	Call to the engine to change the current state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	engine	the engine.
	 * @param [in,out]	state 	the new state.
	 */

	void ChangeState(CoreEngine* engine, State* state);
	bool isPaused(){ return paused; }

	virtual std::string getControlText() const = 0;

	virtual ~State(){}

protected: 
	sf::RenderWindow* window;
	SFMLRenderer renderer; // Should this be here?
	bool paused;
};

