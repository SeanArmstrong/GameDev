#include "IntroState.h"

IntroState::IntroState(const int width, const int height) : State(width, height){
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

	title->SetModelMatrix(Matrix4::Translation(Vector3(screenWidth/2,screenHeight/2,0)) * Matrix4::Scale(Vector3(100,100,0)));

	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, screenWidth, 0, 0, screenHeight));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);
}

void IntroState::Cleanup(){
	ResourceManager::Instance().ResetInstance();
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
		engine.ChangeState(new MainMenuState(screenWidth, screenHeight));
	}

}