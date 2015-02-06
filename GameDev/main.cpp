#include <GL\glew.h>
#include "Singleton.h"
#include "TextureManager.h"
#include "SFMLRenderer.h"
#include "RenderObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include "Matrix3.h"
#include "Matrix4.h"

#include <iostream>

#include "Game.h"


int main() {
	Game game;
	game.run();
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
	
	SFMLRenderer r(width, height);



	Mesh*	m = Mesh::LoadMeshFile("cube.asciimesh");
	Shader* s = new Shader("basicvert.glsl", "basicFrag.glsl");

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
	

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		sf::Int32 elapsed1 = clock.getElapsedTime().asMilliseconds();
		o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Rotation(0.005f, Vector3(1, 0, 1)));


		window.pushGLStates();

		r.UpdateScene(elapsed1);
		r.RenderScene();

		window.popGLStates();

		window.display();
	}
}*/