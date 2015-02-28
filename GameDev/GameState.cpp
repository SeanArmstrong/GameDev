#include "GameState.h"

GameState::GameState(){
	Initialise();
}


GameState::~GameState(){
	Cleanup();
}

void GameState::Initialise(){
	// Load Game resources
	ResourceManager::Instance();
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddShader("Lighting", "NormalsVert.glsl", "PhongFrag.glsl");
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddMeshFile("sphere", 1, "sphere.obj");
	ResourceManager::Instance().AddTexture("brick.jpg");
	// End load resources

	cam.Init();
	renderer.SetShaderLight(Vector3(0, 2000.0f, 0), Vector3(1, 1, 1), 10000.0f);
	renderer.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	renderer.SetViewMatrix(Matrix4::BuildViewMatrix(cam.getPosition(), Vector3(0, 0, -1), cam.getUp()));

	mouseHeld = false;

	GameObject* sphere = new SphereObject();
	sphere->addRenderObjectToWorld(renderer);
	sphere->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	objects.push_back(sphere);

	GameObject* cube = new CubeObject();
	cube->addRenderObjectToWorld(renderer);
	cube->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	objects.push_back(cube);

}
void GameState::Cleanup(){
	ResourceManager::ResetInstance();
}
void GameState::Pause(){
	paused = !paused;
}
void GameState::Resume(){}

void GameState::Update(){
	world.getPhysicsWorld()->stepSimulation(GameTimer::getDelta());

	std::vector<GameObject*>::iterator obj;
	for (obj = objects.begin(); obj < objects.end(); ++obj) {
		(**obj).update();
	}

	//renderer.SetViewMatrix(Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp()) *
		//Matrix4::Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z)));
	//o.SetModelMatrix(Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp()) *
		//Matrix4::Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z)));
	renderer.UpdateScene(GameTimer::getDelta());
}

void GameState::Render(){
	renderer.RenderScene();
}

void GameState::HandleEvents(sf::Event event, const sf::RenderWindow& window){
	float movAmt = (float)(20 * GameTimer::getDelta());
	float rotAmt = (float)(200 * GameTimer::getDelta());

	if (event.type == sf::Event::MouseButtonPressed){
		if (event.mouseButton.button == sf::Mouse::Left){
			std::cout << "Held";
			mouseHeld = true;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased){
		if (event.mouseButton.button == sf::Mouse::Left){
			std::cout << "Released";
			mouseHeld = false;
		}
	}

	switch (event.type){
	case sf::Event::KeyPressed:
		switch (event.key.code){
		case sf::Keyboard::W:
			cam.move(cam.getForward(), movAmt);
			break;
		case sf::Keyboard::A:
			cam.move(cam.getLeft(), movAmt);
			break;
		case sf::Keyboard::S:
			cam.move(cam.getForward(), -movAmt);
			break;
		case sf::Keyboard::D:
			cam.move(cam.getRight(), movAmt);
			break;
		case sf::Keyboard::Up:
			cam.rotateX(rotAmt);
			break;
		case sf::Keyboard::Down:
			cam.rotateX(-rotAmt);
			break;
		case sf::Keyboard::Left:
			cam.rotateY(rotAmt);
			break;
		case sf::Keyboard::Right:
			cam.rotateY(-rotAmt);
			break;
		}
		break;
	}
	if (mouseHeld){
		std::cout << "moving";
		sf::Vector2i position = sf::Mouse::getPosition();

		boolean rotX = position.y != 0;
		boolean rotY = position.x != 0;

		if (rotY){
			cam.rotateY(position.x * 0.001f);
		}
		if (rotX){
			cam.rotateY(-position.y * 0.001f);
		}
		if (rotX || rotY){
			//sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);
		}
	}
}


/*camera stuff

//renderer.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
//renderer.SetViewMatrix(Matrix4::BuildViewMatrix(cam.getPosition(), Vector3(0, 0, -10), cam.getUp()));
//Matrix4 camView = Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp());
//camView.Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z));
*/