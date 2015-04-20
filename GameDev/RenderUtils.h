#pragma once
#include <GL\glew.h>
#include <iostream>

/**
 * @fn	static inline void clearScreen()
 *
 * @brief	Called before rendering every frame
 * 			clears the color and depth buffer
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

static inline void clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

/**
 * @fn	static void initOpenGlStates()
 *
 * @brief	Initialises the open gl states.
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

static void initOpenGlStates(){
	//Set the default background colour
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	//Enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	//Enable Texture Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

/**
 * @fn	static void getOpenGLVersion()
 *
 * @brief	Gets open gl version.
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

static void getOpenGLVersion(){
	std::cout << glGetString(GL_VERSION);
}