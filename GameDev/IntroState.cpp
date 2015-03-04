#include "IntroState.h"

IntroState::IntroState(sf::RenderWindow* w) : State(w){
	Initialise();
}

IntroState::~IntroState(){
	delete title;
}

void IntroState::Initialise(){
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddTexture("splashscreen.png");

	title = new RenderObject(Mesh::GenerateQuad(),
							 ResourceManager::Instance().GetShader("Basic"),
							 ResourceManager::Instance().AddTexture("splashscreen.png"));

	title->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, (float)window->getSize().y / 2, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));

	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, (float)window->getSize().x, 0, 0, (float)window->getSize().y));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);
}

void IntroState::Cleanup(){
	ResourceManager::ResetInstance();
}

void IntroState::Pause(){

}

void IntroState::Resume(){

}

void IntroState::Update(CoreEngine& engine){
	renderer.UpdateScene(GameTimer::getDelta());
}

void IntroState::Render(){
	renderer.RenderScene();
}

void IntroState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyPressed){
		engine.ChangeState(new MainMenuState(window));
	}

}