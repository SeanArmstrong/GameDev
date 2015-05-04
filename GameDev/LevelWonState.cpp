#include "LevelWonState.h"


LevelWonState::LevelWonState(sf::RenderWindow* w, const std::string message) : State(w)
{
	this->messageString = message;
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

	font.loadFromFile("assets/fonts/arial.ttf");

	messageText.setFont(font);
	messageText.setCharacterSize(20);
	messageText.setPosition(sf::Vector2f(500, 500));
	messageText.setColor(sf::Color::White);
	messageText.setStyle(sf::Text::Regular);
	messageText.setString(messageString);
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
	window->pushGLStates();
	window->draw(messageText);
	window->popGLStates();
}

void LevelWonState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
		ResourceManager::ResetInstance();
		engine.ChangeState(new MainMenuState(window));
	}
}

std::string LevelWonState::getControlText() const{
	return "Press Space Bar To Continue";
}
