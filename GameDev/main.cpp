#include <GL\glew.h>
#include "Singleton.h"
#include "TextureManager.h"
#include "SFMLRenderer.h"
#include "RenderObject.h"
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include "Matrix3.h"
#include "Matrix4.h"

#include <iostream>

#include "Game.h"


int main() {
	Game game;
	game.run();

	return 0;
}

/*void main(void) {
	
	int width = 640;
	int height = 480;

	sf::RenderWindow window(sf::VideoMode(width, height), "Platform Game");
	
	// Taken from OGLRenderer
	if (glewInit() != GLEW_OK) {	//Try to initialise GLEW
		std::cout << "OGLRenderer::OGLRenderer(): Cannot initialise GLEW!" << std::endl;
		return;
	}
	
	SFMLRenderer r;
	


	Mesh*	m = Mesh::LoadMeshFile("cube.asciimesh");
	Shader* s = new Shader("assets/shaders/basicvert.glsl", "assets/shaders/textureFrag.glsl");

	if (s->UsingDefaultShader()) {
		cout << "Warning: Using default shader! Your shader probably hasn't worked..." << endl;
		cout << "Press any key to continue." << endl;
		std::cin.get();
	}

	RenderObject o(m, s);
	o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));

	r.AddRenderObject(o);

	sf::Clock clock;
	r.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	r.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
	
	//Set the default background colour
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	//Enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	//Enable Texture Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}
		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//window.clear();

		sf::Int32 elapsed1 = clock.getElapsedTime().asMilliseconds();
		o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Rotation(0.005f, Vector3(1, 0, 1)));
		
		window.resetGLStates();
		//glDepthFunc(GL_TRUE);
		//window.pushGLStates();


		r.UpdateScene(elapsed1);
		r.RenderScene();

		window.display();

		//window.popGLStates();

	}
}*/