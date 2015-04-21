#include "Level1.h"


Level1::Level1(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r){
	Initialise();
}


Level1::~Level1(){
}

void Level1::Initialise(){
	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 30.0f;
}

void Level1::GameLogic(CoreEngine& engine){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		GameObject* cube = player->spawnCube();
		if (cube){
			cube->addRenderObjectToWorld(*renderer);
			cube->addPhysicsObjectToWorld(*world.getPhysicsWorld());
			worldObjects.push_back(cube);
		}
	}

	if (!player->isAlive() || timer <= 0.0f){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		engine.ChangeState(new LevelLostState(window));
	}
	if (player->getScore() == 3){ // this(scene).score){
		ResourceManager::Instance().AudioPlaySound("Clapping.wav");
		engine.ChangeState(new LevelWonState(window));
	}
}

void Level1::SetView(){
	renderer->SetShaderLight(Vector3(0, 2000.0f, 0), Vector3(1, 1, 1), 10000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void Level1::LoadResources(){
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
}

void Level1::LoadMap(){
	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, 40);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	GameObject* cube1 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, 0), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	cube1->addRenderObjectToWorld(*renderer);
	cube1->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube1);

	GameObject* cube2 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -120), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	cube2->addRenderObjectToWorld(*renderer);
	cube2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube2);

	GameObject* cube3 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(165, 0, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube3->addRenderObjectToWorld(*renderer);
	cube3->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube3);

	GameObject* cube4 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-165, 0, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube4->addRenderObjectToWorld(*renderer);
	cube4->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube4);

	GameObject* cube5 = new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -295), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg"));
	cube5->addRenderObjectToWorld(*renderer);
	cube5->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(cube5);
}

void Level1::LoadObjects(){
	GameObject* coin = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 52, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin->addRenderObjectToWorld(*renderer);
	coin->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin);

	GameObject* coin2 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(30, 52, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin2->addRenderObjectToWorld(*renderer);
	coin2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin2);

	GameObject* coin3 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 52, -55), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	coin3->addRenderObjectToWorld(*renderer);
	coin3->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(coin3);
}

void Level1::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 50, 20), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	player->addRenderObjectToWorld(*renderer);
	player->addPhysicsObjectToWorld(*world.getPhysicsWorld());
}
