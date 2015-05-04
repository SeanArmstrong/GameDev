#pragma once
#include "RenderObject.h"
#include "SFMLRenderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include "Matrix3.h"
#include "Matrix4.h"
#include "State.h"
#include <vector>
#include "GameTimer.h"
#include "RenderUtils.h"
#include "DebugHUD.h"
#include "ControlHUD.h"

class State;

/**
 * @class	CoreEngine
 *
 * @brief	Core Engine for game. 
 * 			Initialises the SFML Render Window.
 * 			Each screen - Info, Menu, Settings, Game are controlled by a state 
 * 			systems where they are poped and push on and off the stack
 * 			
 * 			Contains game loop which calls update, render, handleevents on the state
 * 			at the top of the stack
 * 			
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CoreEngine
{
public:

	/**
	 * @fn	CoreEngine::CoreEngine(const int width, const int height, const float framerate);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	width	 	The width of the window.
	 * @param	height   	The height of the window.
	 * @param	framerate	The framerate of the window.
	 */
	CoreEngine(const int width, const int height, const float framerate);
	~CoreEngine();

	/**
	 * @fn	void CoreEngine::run();
	 *
	 * @brief	Initialises the window and then starts game loop
	 * 			with the inital state of IntroState
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void run();

	/**
	 * @fn	void CoreEngine::Cleanup();
	 *
	 * @brief	Removes all states and cleanup resources
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void Cleanup();

	/**
	 * @fn	void CoreEngine::ChangeState(State* state);
	 *
	 * @brief	Changes the state of the engine. Popping off the current
	 * 			state and adding the newly passed state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	state	If non-null, the new state.
	 */

	void ChangeState(State* state);

	/**
	 * @fn	void CoreEngine::PushState(State* state);
	 *
	 * @brief	Pushes a state onto the stack
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	state	If non-null, the new state.
	 */

	void PushState(State* state);

	/**
	 * @fn	void CoreEngine::PopState();
	 *
	 * @brief	Pops off the top elemetn fo the stack
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void PopState();

	/**
	 * @fn	void CoreEngine::HandleEvents(sf::Event event);
	 *
	 * @brief	it then calls the current states handleevents method
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	event	The event.
	 */

	void HandleEvents(sf::Event event);

	/**
	 * @fn	void CoreEngine::Update(const float& msec);
	 *
	 * @brief	Calls the update function of the current state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	msec	The delta time.
	 */

	void Update(const float& msec);

	/**
	 * @fn	void CoreEngine::Render(const float& msec);
	 *
	 * @brief	Calls the render function of the current state
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	msec	The msec.
	 */

	void Render(const float& msec);

	/**
	 * @fn	bool CoreEngine::Running()
	 *
	 * @brief	Returns true if the engine is running 
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	true if it is running, false if it is not.
	 */

	bool Running() { return running; }

	/**
	 * @fn	void CoreEngine::Quit()
	 *
	 * @brief	Quits the running loop.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void Quit() { running = false; }

	sf::RenderWindow* getWindow();

private:

	/**
	 * @fn	void CoreEngine::Initialise();
	 *
	 * @brief	Initialises this object. 
	 * 			RenderWindow created
	 * 			Glew.init
	 * 			Init opengl states
	 * 			sets running to true
	 * 			
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void Initialise();

	/**
	 * @fn	void CoreEngine::gameLoop();
	 *
	 * @brief	Game loop of the system
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void gameLoop();

	/**
	 * @fn	void CoreEngine::processInput();
	 *
	 * @brief	Process the input. such as ESC key
	 * 			for closing input
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void processInput();

	void setChangeStateInfo();

	sf::RenderWindow window;
	std::vector<State*> states;

	int screenWidth;
	int screenHeight;
	float framerate;

	bool running;
	bool polygons;
	bool showDebugInfo;
	bool showControls = true;

	DebugHUD debugInfo;
	ControlHUD controlInfo;
	
};

