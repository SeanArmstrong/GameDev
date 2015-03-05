#include "GameState.h"

GameState::GameState(sf::RenderWindow* w) : State(w), hud(w->getSize().x, w->getSize().y){
	Initialise();
}


GameState::~GameState(){
	delete player;
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete worldObjects[i];
	}
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete eventObjects[i];
	}
}


void GameState::Initialise(){
	// Load Game resources
	ResourceManager::Instance();
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddShader("BasicRepeating", "basicvert.glsl", "textureRepeatFrag.glsl");
	ResourceManager::Instance().AddShader("Lighting", "NormalsVert.glsl", "PhongFrag.glsl");
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddMeshFile("sphere", 1, "sphere.obj");
	ResourceManager::Instance().AddMeshFile("coin", 1, "coin3.obj");
	ResourceManager::Instance().AddTexture("brick.jpg");
	ResourceManager::Instance().AddTexture("terrain.jpg");
	ResourceManager::Instance().AddTexture("ground.jpg");
	ResourceManager::Instance().AddTexture("checkboard.jpg");
	ResourceManager::Instance().AddTexture("coin.jpg");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");

	// End load resources
	loadScene();
	mouseHeld = false;
	timer = 30.0f;
}

void GameState::Pause(){
	paused = !paused;
}

void GameState::Resume(){}


void GameState::Update(CoreEngine& engine){
	world.getPhysicsWorld()->stepSimulation(GameTimer::getDelta());
	world.callbackChecker(player, eventObjects);
	removeDeletedObjects();

	player->update();

	timer = timer - GameTimer::getDelta();

	gameLogic(engine);

	std::vector<GameObject*>::iterator obj;
	for (obj = worldObjects.begin(); obj < worldObjects.end(); ++obj) {
		(**obj).update();
	}

	for (obj = eventObjects.begin(); obj < eventObjects.end(); ++obj) {
		(**obj).update();
	}

	renderer.SetViewMatrix(cam.setPlayerCam(player->getPhysicsObject()/*, rotateAmount*/));
	renderer.UpdateScene(GameTimer::getDelta());

	hud.Update(*player, timer);
}

void GameState::gameLogic(CoreEngine& engine){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		GameObject* cube = player->spawnCube();
		if (cube){
			cube->addRenderObjectToWorld(renderer);
			cube->addPhysicsObjectToWorld(*world.getPhysicsWorld());
			worldObjects.push_back(cube);
		}
	}

	// Check for end of game;
	if (!player->isAlive() || timer <= 0.0f){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		engine.ChangeState(new LevelLostState(window));
	}
	if (player->getScore() == 3){ // this(scene).score){
		ResourceManager::Instance().AudioPlaySound("Clapping.wav");
		engine.ChangeState(new LevelWonState(window));
	}
}


void GameState::Render(){
	renderer.RenderScene();
	hud.Draw(window);
	//world.getPhysicsWorld()->debugDrawWorld();
}


void GameState::HandleEvents(CoreEngine& engine, sf::Event event){
	if (event.key.code == sf::Keyboard::Escape){
		engine.ChangeState(new MainMenuState(window));
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

	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -30);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 20), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	player->addRenderObjectToWorld(renderer);
	player->addPhysicsObjectToWorld(*world.getPhysicsWorld());

	GameObject* coin = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -18, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin->addRenderObjectToWorld(renderer);
	coin->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin);

	GameObject* coin2 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(30, -18, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin2->addRenderObjectToWorld(renderer);
	coin2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin2);

	GameObject* coin3 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, -18, -55), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin3->addRenderObjectToWorld(renderer);
	coin3->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin3);

	GameObject* cube1 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, -70, 0), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	cube1->addRenderObjectToWorld(renderer);
	cube1->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube1);

	GameObject* cube2 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, -70, -120), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	cube2->addRenderObjectToWorld(renderer);
	cube2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube2);

	GameObject* cube3 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(165, -70, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube3->addRenderObjectToWorld(renderer);
	cube3->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube3);

	GameObject* cube4 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-165, -70, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube4->addRenderObjectToWorld(renderer);
	cube4->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube4);

	GameObject* cube5 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, -70, -295), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube5->addRenderObjectToWorld(renderer);
	cube5->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube5);
}

void GameState::removeDeletedObjects(){
	std::set<int> elementsToRemove;

	for (unsigned int i = 0; i < eventObjects.size(); ++i){
		if (!(*eventObjects[i]).getExistsInWorld()){
			elementsToRemove.insert(i);
		}
	}
	std::set<int>::reverse_iterator rit;
	for (rit = elementsToRemove.rbegin(); rit != elementsToRemove.rend(); ++rit){
		(eventObjects[*rit])->removePhysicsObjectFromWorld(*world.getPhysicsWorld());
		(eventObjects[*rit])->removeRenderObjectFromWorld(renderer);
		eventObjects.erase(eventObjects.begin() + *rit);
	}
}