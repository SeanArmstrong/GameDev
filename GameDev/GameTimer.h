#pragma once

#include <time.h>
#include <Windows.h>
#include <iostream>

/**
 * @class	GameTimer
 *
 * @brief	Class to manage game timer throughout the system
 * 			Tracks total passed time and has setter and
 * 			getter for delta which will be used
 * 			for frame rate by the core engine and then used
 * 			throughout the engine.
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class GameTimer
{
public:

	/**
	 * @fn	static float GameTimer::getTime();
	 *
	 * @brief	Gets the time passed
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	The time.
	 */

	static float getTime();

	/**
	 * @fn	static float GameTimer::getDelta();
	 *
	 * @brief	Gets the delta time (change in time)
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	The delta.
	 */

	static float getDelta();

	/**
	 * @fn	static void GameTimer::setDelta(const float& d);
	 *
	 * @brief	Sets a delta time to given d
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	d	The given delta time to set
	 */

	static void setDelta(const float& d);

private:
	static float delta;
	static bool initialised;
	static float freq;
};
