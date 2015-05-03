#include "LevelLostState.h"


LevelLostState::LevelLostState(sf::RenderWindow* w, const std::string message) : State(w)
{
	this->messageString = message;
	Initialise();
}


LevelLostState::~LevelLostState(){}

void LevelLostState::Initialise(){
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddTexture("lost.png");

	title = new RenderObject(Mesh::GenerateQuad(),
		ResourceManager::Instance().GetShader("Basic"),
		ResourceManager::Instance().AddTexture("lost.png"));

	title->SetModelMatrix(Matrix4::Translation(Vector3((float)window->getSize().x / 2, (float)window->getSize().y / 2, 0)) * Matrix4::Scale(Vector3(100, 100, 0)));

	renderer.SetProjectionMatrix(Matrix4::Orthographic(-1, 1, (float)window->getSize().x, 0, 0, (float)window->getSize().y));
	Matrix4 view;
	view.ToIdentity();
	renderer.SetViewMatrix(view);
	renderer.AddRenderObject(*title);

	font.loadFromFile("assets/fonts/arial.ttf");

	messageText.setFont(font);
	messageText.setCharacterSize(20);
	messageText.setPosition(sf::Vector2f(500, 500));
	messageText.setColor(sf::Color::White);
	messageText.setStyle(sf::Text::Regular);
	messageText.setString(messageString);
}

void LevelLostState::Pause(){

}

void LevelLostState::Resume(){

}

void LevelLostState::Update(CoreEngine& engine){
	renderer.UpdateScene(GameTimer::getDelta());
}

void LevelLostState::Render(){
	renderer.RenderScene();
	window->pushGLStates();
	window->draw(messageText);
	window->popGLStates();
}

void LevelLostState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyPressed){
		ResourceManager::ResetInstance();
		engine.ChangeState(new MainMenuState(window));
	}
}
