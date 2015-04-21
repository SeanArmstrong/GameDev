#include "Level2.h"
#include "LevelLostState.h"
#include "LevelWonState.h"


Level2::Level2(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r) {
	Initialise();
}


Level2::~Level2()
{
}

void Level2::Initialise(){
	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 30.0f;
}

void Level2::GameLogic(CoreEngine& engine){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		GameObject* cube = player->spawnCube();
		if (cube){
			cube->addRenderObjectToWorld(*renderer);
			cube->addPhysicsObjectToWorld(*world.getPhysicsWorld());
			worldObjects.push_back(cube);
		}
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
	//	world.getPhysicsWorld()->setGravity(btVector3(9.81f, 0, 0));
	//}

	if (!player->isAlive() || timer <= 0.0f){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		engine.ChangeState(new LevelLostState(window));
	}
	if (player->getScore() == 3){ // this(scene).score){
		ResourceManager::Instance().AudioPlaySound("Clapping.wav");
		engine.ChangeState(new LevelWonState(window));
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
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
}

void Level2::LoadMap(){
	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -30);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

}

void Level2::LoadObjects(){
	GameObject* platform1 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, 0), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	platform1->addRenderObjectToWorld(*renderer);
	platform1->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(platform1);

	GameObject* platform2 = new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 10, 0), 0, 0.2f, 10, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	platform2->addRenderObjectToWorld(*renderer);
	platform2->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	worldObjects.push_back(platform2);
}

void Level2::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	player->addRenderObjectToWorld(*renderer);
	player->addPhysicsObjectToWorld(*world.getPhysicsWorld());
}