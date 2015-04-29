#include "LevelWonState.h"


LevelWonState::LevelWonState(sf::RenderWindow* w) : State(w)
{
	Initialise();
}


LevelWonState::~LevelWonState()
{
	//delete title;
}

void LevelWonState::Initialise(){
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddTexture("winner.png");

	title = new RenderObject(Mesh::GenerateQuad(),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().AddTexture("winner.png"));

	title->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, (float)window->getSize().y / 2, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));

	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, (float)window->getSize().x, 0, 0, (float)window->getSize().y));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);
}

void LevelWonState::Pause(){

}

void LevelWonState::Resume(){

}

void LevelWonState::Update(CoreEngine& engine){
	renderer.UpdateScene(GameTimer::getDelta());
}

void LevelWonState::Render(){
	renderer.RenderScene();
}

void LevelWonState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyPressed){
		ResourceManager::ResetInstance();
		engine.ChangeState(new MainMenuState(window));
	}
}
