#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* w) : State(w){
	Initialise();
}

MainMenuState::~MainMenuState(){
	delete title;
}

void MainMenuState::Initialise(){
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddTexture("splashscreen.png");

	title = new RenderObject(Mesh::GenerateQuad(),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().AddTexture("menu.png"));

	title->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, (float)window->getSize().y / 2, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));

	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, (float)window->getSize().x, 0, 0, (float)window->getSize().y));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);
}

void MainMenuState::Pause(){

}

void MainMenuState::Resume(){

}

void MainMenuState::Update(CoreEngine& engine){
	renderer.UpdateScene(GameTimer::getDelta());
}

void MainMenuState::Render(){
	renderer.RenderScene();
}

void MainMenuState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.key.code == sf::Keyboard::Return){
		engine.ChangeState(new GameState(window));
	}

}