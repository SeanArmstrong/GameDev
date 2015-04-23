#include "Level2.h"


Level2::Level2(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r) {
	Initialise();
}


Level2::~Level2()
{
}

void Level2::Initialise(){
	gravityOn = true;
	levelScore = 3;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 60.0f;
}

void Level2::GameLogic(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		GameObject* cube = player->spawnCube();
		if (cube){
			addWorldObject(cube);
		}
	}
}

void Level2::SetView(){
	renderer->SetShaderLight(Vector3(0, 2000.0f, 0), Vector3(1, 1, 1), 10000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void Level2::LoadResources(){
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
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddMeshFile("funkyshape", 1, "funkyshape.obj");
	ResourceManager::Instance().AddMeshFile("pooltable", 1, "pooltable.obj");
}

void Level2::LoadMap(){
	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -30);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	GameObject* platform1 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, 0), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform1);

	GameObject* platform2 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 10, 0), 0, 0.2f, 10, 10, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform2);

	GameObject* platform3 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 10, 0), 0, 0.2f, 10, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform3);

	GameObject* platform4 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 20, 0), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform4);

	GameObject* special1 = new ConvexGameObject(ResourceManager::Instance().GetShader("Basic"), "funkyshape", Vector3(0, 2, 0), 0, 2, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(special1);

	//GameObject* special2 = new ConcaveGameObject(ResourceManager::Instance().GetShader("Basic"), "pooltable", Vector3(0, 0, 0), 0, 35, ResourceManager::Instance().AddTexture("pool2.png"));
	//addWorldObject(special2);
}

void Level2::LoadObjects(){

}

void Level2::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	addEventObject(player);
}