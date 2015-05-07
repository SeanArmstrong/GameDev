#include "Level1.h"


Level1::Level1(sf::RenderWindow* w, SFMLRenderer* r) : SinglePlayerLevel(w, r){
	Initialise();
}


Level1::~Level1(){
}

void Level1::Initialise(){
	gravityOn = false;
	levelScore = 3;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 30.0f;
	cam = new PlayerFollowCamera();
	setObjectiveHUDText();
	ResourceManager::Instance().AudioPlayAndLoopMusic("retro2.wav");
}

void Level1::GameLogic(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		GameObject* cube = player->spawnCube();
		if (cube){
			cube->addRenderObjectToWorld(*renderer);
			cube->addPhysicsObjectToWorld(*world.getPhysicsWorld());
			worldObjects.push_back(cube);
		}
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
	ResourceManager::Instance().AddShader("skybox", "SkyboxVert.glsl", "SkyboxFrag.glsl");
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddMeshFile("sphere", 1, "sphere.obj");
	ResourceManager::Instance().AddMeshFile("coin", 1, "coin3.obj");
	ResourceManager::Instance().AddTexture("brick.jpg");
	ResourceManager::Instance().AddTexture("terrain.jpg");
	ResourceManager::Instance().AddTexture("ground.jpg");
	ResourceManager::Instance().AddTexture("fire.png");
	ResourceManager::Instance().AddTexture("checkboard.jpg");
	ResourceManager::Instance().AddTexture("coin.jpg");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddSound("Checkpoint.wav");
	ResourceManager::Instance().AddMusic("retro2.wav");
	ResourceManager::Instance().AddSkybox("rustskybox", "rusted_west.jpg", "rusted_east.jpg", "rusted_up.jpg", "rusted_down.jpg", "rusted_south.jpg", "rusted_north.jpg");
}

void Level1::LoadMap(){
	this->renderer->setSkybox(new Skybox("rustskybox"));

	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, 40);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, 0), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg")));
	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -120), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg")));
	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(165, 0, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg")));
	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-165, 0, -65), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg")));
	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -295), 0, 115, ResourceManager::Instance().AddTexture("brick.jpg")));

}

void Level1::LoadObjects(){
	GameObject* coin1 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 52, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	addEventObject(coin1);

	GameObject* coin2 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(30, 52, -120), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	addEventObject(coin2);

	GameObject* coin3 = new CoinGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 52, -55), 0, 1, ResourceManager::Instance().AddTexture("coin.jpg"));
	addEventObject(coin3);
}

void Level1::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 50, 20), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"), 3);
	addEventObject(player);
	players.push_back(player);
}

void Level1::setObjectiveHUDText(){
	objectiveHUD.SetControlText("Level 1: Collect ALL the coins");
}

void* Level1::operator new(size_t i)
{
	return _mm_malloc(i, 16);
}

void Level1::operator delete(void* p)
{
	_mm_free(p);
}