#include "GameState.h"

GameState::GameState(const float& width, const float& height) : State(width, height){
	Initialise();
}


GameState::~GameState(){
	delete player;
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete worldObjects[i];
	}
}

void GameState::Initialise(){
	// Load Game resources
	ResourceManager::Instance();
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddShader("Lighting", "NormalsVert.glsl", "PhongFrag.glsl");
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddMeshFile("sphere", 1, "sphere.obj");
	ResourceManager::Instance().AddMeshFile("coin", 1, "coin3.obj");
	ResourceManager::Instance().AddTexture("brick.jpg");
	ResourceManager::Instance().AddTexture("ground.jpg");
	ResourceManager::Instance().AddTexture("checkboard.jpg");
	ResourceManager::Instance().AddTexture("coin.jpg");
	// End load resources

	loadScene();
	mouseHeld = false;
}
void GameState::Cleanup(){
	ResourceManager::Instance().ResetInstance();
}
void GameState::Pause(){
	paused = !paused;
}
void GameState::Resume(){}



void GameState::Update(){
	world.getPhysicsWorld()->stepSimulation(GameTimer::getDelta());

	player->update();

	std::vector<GameObject*>::iterator obj;
	for (obj = worldObjects.begin(); obj < worldObjects.end(); ++obj) {
		(**obj).update();
	}

	renderer.SetViewMatrix(cam.setPlayerCam(player->getPhysicsObject()/*, rotateAmount*/));
	//renderer.SetViewMatrix(Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp()) *
		//Matrix4::Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z)));
	//o.SetModelMatrix(Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp()) *
		//Matrix4::Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z)));
	renderer.UpdateScene(GameTimer::getDelta());

	int action = world.callbackChecker();
	if (action == 1){
		// Collect coin
	}
	else if (action == 9){
		endGame = true;
	}
}



void GameState::Render(){
	renderer.RenderScene();
	//world.getPhysicsWorld()->debugDrawWorld();
}


void GameState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (endGame || event.key.code == sf::Keyboard::Escape){
		engine.ChangeState(new MainMenuState(screenWidth, screenHeight));
	}

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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		std::cout << "Forward";
		player->moveForward();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		player->moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		player->moveBackwards();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		player->moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		player->jump();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
		rotateAmount = -1.0f;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		rotateAmount = 1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		std::cout << "UP" << std::endl;
		cam.rotateX(rotAmt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		cam.rotateX(-rotAmt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		cam.rotateY(rotAmt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		cam.rotateY(-rotAmt);
	}

	/*
	switch (event.type){
	case sf::Event::KeyPressed:
		switch (event.key.code){
		case sf::Keyboard::I:
			cam.move(cam.getForward(), movAmt);
			break;
		case sf::Keyboard::J:
			cam.move(cam.getLeft(), movAmt);
			break;
		case sf::Keyboard::K:
			cam.move(cam.getForward(), -movAmt);
			break;
		case sf::Keyboard::L:
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
	}*/
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

void GameState::resetScene(){
	delete player;
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete worldObjects[i];
	}

	loadScene();
}

void GameState::loadScene(){
	cam.Init();
	renderer.SetShaderLight(Vector3(0, 2000.0f, 0), Vector3(1, 1, 1), 10000.0f);
	renderer.SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
	cam.setPosition(Vector3(0.0f, -25.0f, -25.0f));
	cam.setForward(Vector3(0.05f, 0.5f, 0.9f));
	cam.setUp(Vector3(0.02f, 0.9f, -0.5f));
	renderer.SetViewMatrix(Matrix4::BuildViewMatrix(cam.getPosition(), Vector3(0, 0, -1), cam.getUp()));

	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -30
		/*ResourceManager::Instance().GetShader("Basic"), ResourceManager::Instance().AddTexture("checkboard.jpg")*/);
	//invisibleGround->addRenderObjectToWorld(renderer);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(invisibleGround);

	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, -10), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	player->addRenderObjectToWorld(renderer);
	player->addPhysicsObjectToWorld(*world.getPhysicsWorld());

	GameObject* coin = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -18, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin->addRenderObjectToWorld(renderer);
	coin->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(coin);

	GameObject* cube1 = new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -70, 0), 0, 50, ResourceManager::Instance().AddTexture("ground.jpg"));
	cube1->addRenderObjectToWorld(renderer);
	cube1->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube1);

	GameObject* cube2 = new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -70, -120), 0, 50, ResourceManager::Instance().AddTexture("ground.jpg"));
	cube2->addRenderObjectToWorld(renderer);
	cube2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube2);

	GameObject* cube3 = new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(165, -70, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube3->addRenderObjectToWorld(renderer);
	cube3->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube3);

	GameObject* cube4 = new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-165, -70, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube4->addRenderObjectToWorld(renderer);
	cube4->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube4);

	GameObject* cube5 = new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -70, -295), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube5->addRenderObjectToWorld(renderer);
	cube5->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube5);
}

/*camera stuff

//renderer.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
//renderer.SetViewMatrix(Matrix4::BuildViewMatrix(cam.getPosition(), Vector3(0, 0, -10), cam.getUp()));
//Matrix4 camView = Matrix4::BuildCameraMatrix(cam.getForward(), cam.getUp());
//camView.Translation(Vector3(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z));
*/