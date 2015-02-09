#include "GameState.h"

GameState::GameState(){
	Initialise();
}


GameState::~GameState(){
	Cleanup();
}

void GameState::Initialise(){
	// Load Game resources
	//ResourceManager::Instance().//DO SOMETHING

	renderer = SFMLRenderer();
	//Mesh* m = Mesh::LoadMeshFile("cube.asciimesh");
	Mesh* m = Mesh::LoadMeshObj("assets/models/cube.obj");
	//Mesh* m = Mesh::LoadMeshObj("assets/models/sphere.obj");
	Shader* s = new Shader("assets/shaders/basicvert.glsl", "assets/shaders/textureFrag.glsl");

	o.Intialize(m, s);

	o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
	renderer.AddRenderObject(o);

	renderer.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	renderer.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));

}
void GameState::Cleanup(){
	// Delete stuff
}
void GameState::Pause(){}
void GameState::Resume(){}
void GameState::HandleEvents(sf::Event event){
	switch (event.type){
	case sf::Event::KeyPressed:
		switch (event.key.code){
		case sf::Keyboard::W: // Forward
			std::cout << "Forward";
			o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Translation(Vector3(0, 0, -0.1f)));
			break;
		case sf::Keyboard::A: // Left
			o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Translation(Vector3(-0.1f, 0, 0)));
			break;
		case sf::Keyboard::S: // Back
			o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Translation(Vector3(0, 0, 0.1f)));
			break;
		case sf::Keyboard::D: // Right
			o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Translation(Vector3(0.1f, 0, 0)));
			break;
		}
	}

}

void GameState::Update(){
	renderer.UpdateScene(1.0);
}

void GameState::Render(){
	renderer.RenderScene();
}
