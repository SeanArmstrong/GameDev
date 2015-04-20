#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* w) : State(w){
	Initialise();
}

MainMenuState::~MainMenuState(){
	delete title;
	delete play;
}

void MainMenuState::Initialise(){
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");

	title = new RenderObject(Mesh::GenerateQuad(),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().AddTexture("menu.png"));

	float percentX = (float)window->getSize().x * 0.01f;
	float percentY = (float)window->getSize().y * 0.01f;

	title->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, percentY * 30, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));


	play = new RenderObject(Mesh::GenerateQuad(),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().AddTexture("menu.png"));

	play->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, percentY * 60, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));


	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, (float)window->getSize().x, 0, 0, (float)window->getSize().y));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);
	renderer.AddRenderObject(*play);

	elementSelected = 0;
	actions[0] = play;
	actions[1] = settings;
	actions[2] = quit;
}

void MainMenuState::Pause(){

}

void MainMenuState::Resume(){

}

void MainMenuState::Update(CoreEngine& engine){
	renderer.UpdateScene(GameTimer::getDelta());

	//std::cout << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		elementSelected--;
		if (elementSelected < 0){
			elementSelected = 2;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		elementSelected = (elementSelected + 1) % 3;
	}
	std::cout << elementSelected << std::endl;
	switch (elementSelected){
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

void MainMenuState::Render(){
	renderer.RenderScene();
}

void MainMenuState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.key.code == sf::Keyboard::Return){
		engine.ChangeState(new GameState(window));
	}

}