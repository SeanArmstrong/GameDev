#pragma once
#include <GL\glew.h>
#include <iostream>

static inline void clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

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

static void getOpenGLVersion(){
	std::cout << glGetString(GL_VERSION);
}