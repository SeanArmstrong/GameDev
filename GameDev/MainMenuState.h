#pragma once
#include "State.h"
#include "RenderObject.h"
#include "ResourceManager.h"
#include "GameState.h"

/**
 * @class	MainMenuState
 *
 * @action - Press enter/return to continue
 * 
 * @brief	A State for the main menu of the page
 * 			This currently links to the game state and is
 * 			gotton to by from the intro, win and fail states
 * 			
 * 			The plan for this states:
 * 			Mouse click on appopriate action
 * 			link to settings
 * 			multi level select
 * 			quit button
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

#define MAX_NUMBER_OF_ITEMS 6
#define NON_SELECTABLE_ITEMS 2

class MainMenuState : public State
{
public:

	/**
	 * @fn	MainMenuState::MainMenuState(sf::RenderWindow* w);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 *
	 * @param [in,out]	w	If non-null, the sf::RenderWindow* to process.
	 */

	MainMenuState(sf::RenderWindow* w);

	/**
	 * @fn	virtual MainMenuState::~MainMenuState();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual ~MainMenuState();

	/**
	 * @fn	virtual void MainMenuState::Initialise();
	 *
	 * @brief	Initialises this object.
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual void Initialise();

	/**
	 * @fn	virtual void MainMenuState::Pause();
	 *
	 * @brief	Pauses this object.
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual void Pause();

	/**
	 * @fn	virtual void MainMenuState::Resume();
	 *
	 * @brief	Resumes this object if paused
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual void Resume();

	/**
	 * @fn	virtual void MainMenuState::HandleEvents(CoreEngine& engine, sf::Event event);
	 *
	 * @brief	Handles the events such as closing of windows and moving between states
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 * @param	event		  	The event.
	 */

	virtual void HandleEvents(CoreEngine& engine, sf::Event event);

	/**
	 * @fn	virtual void MainMenuState::Update(CoreEngine& engine);
	 *
	 * @brief	Update called every frame to update render objects
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 *
	 * @param [in,out]	engine	The engine.
	 */

	virtual void Update(CoreEngine& engine);

	/**
	 * @fn	virtual void MainMenuState::Render();
	 *
	 * @brief	Renders this object every frame
	 *
	 * @author	Sean Armstrong
	 * @date	08/03/2015
	 */

	virtual void Render();

	virtual std::string getControlText() const;


	void MoveUp();
	void MoveDown();



protected:

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text nonSelectMenu[NON_SELECTABLE_ITEMS];

};
