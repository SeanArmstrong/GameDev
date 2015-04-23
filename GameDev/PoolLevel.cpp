#include "PoolLevel.h"


PoolLevel::PoolLevel(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r) {
	Initialise();
}


PoolLevel::~PoolLevel(){
}

void PoolLevel::Initialise(){
	gravityOn = false;
	levelScore = 300000;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 300.0f;
	world.getPhysicsWorld()->setGravity(btVector3(0, -30.0f, 0));
}

void PoolLevel::GameLogic(){

}

void PoolLevel::SetView(){
	renderer->SetShaderLight(Vector3(0, 1000.0f, 0), Vector3(1, 1, 1), 1000000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void PoolLevel::LoadResources(){
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
	ResourceManager::Instance().AddTexture("pool2.png");
	ResourceManager::Instance().AddTexture("redball.png");
	ResourceManager::Instance().AddTexture("yellowball.png");
	ResourceManager::Instance().AddTexture("blackball.png");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("BallClick.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddMeshFile("funkyshape", 1, "funkyshape.obj");
	ResourceManager::Instance().AddMeshFile("pooltable", 1, "pooltable.obj");
}

void PoolLevel::LoadMap(){
	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -15);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	GameObject* special2 = new ConcaveGameObject(ResourceManager::Instance().GetShader("Basic"), "pooltable", Vector3(0, 0, 0), 0, 35, ResourceManager::Instance().AddTexture("pool2.png"));
	addWorldObject(special2);
}

void PoolLevel::LoadObjects(){
	GameObject* yellow;
	GameObject* red;

	// Top
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(86.0f, -8.0f, -19.5f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Second right
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(88.0f, -8.0f, -20.0f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Second Left
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(88.0f, -8.0f, -19.0f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

	// Third Middle
	GameObject* black = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(90.0f, -7.58f, -19.5f), 1, 1, PoolBallGameObject::Type::Black, ResourceManager::Instance().AddTexture("blackball.png"));
	addEventObject(black);

	// Third left
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(90.0f, -7.58f, -20.5f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Third Right
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(90.0f, -7.58f, -18.5f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

	// Fourth Middle Left
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(92.0f, -7.58f, -19.0f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Fourth Middle Right
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(92.0f, -7.58f, -20.0f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

	// Fourth Left
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(92.0f, -7.58f, -21.0f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

	// Fourth Right
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(92.0f, -7.58f, -18.0f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Fifth Middle
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(94.0f, -7.58f, -19.5f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Fifth Middle Left
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(94.0f, -7.58f, -20.5f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

	// Fifth Middle Right
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(94.0f, -7.58f, -18.5f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Fifth Left
	red = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(94.0f, -7.58f, -17.5f), 1, 1, PoolBallGameObject::Type::Red, ResourceManager::Instance().AddTexture("redball.png"));
	addEventObject(red);

	// Fifth Middle Left
	yellow = new PoolBallGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(94.0f, -7.58f, -21.5f), 1, 1, PoolBallGameObject::Type::Yellow, ResourceManager::Instance().AddTexture("yellowball.png"));
	addEventObject(yellow);

}

void PoolLevel::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Lighting"), Vector3(-33.7f, -7.58f, -20.5f), 10, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"), 200.0f);
	addEventObject(player);
	CollisionResponse::setPlayer(player);
}
