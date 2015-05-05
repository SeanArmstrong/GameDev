#include "Level4.h"


Level4::Level4(sf::RenderWindow* w, SFMLRenderer* r) : SinglePlayerLevel(w, r){
	Initialise();
}


Level4::~Level4()
{
}

void Level4::Initialise(){
	gravityOn = true;
	levelScore = 3;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 30.0f;
	cam = new PlayerFollowCamera();
	setObjectiveHUDText();
}

void Level4::GameLogic(){

}

void Level4::SetView(){
	renderer->SetShaderLight(Vector3(0, 2000.0f, 0), Vector3(1, 1, 1), 10000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void Level4::LoadResources(){
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
	ResourceManager::Instance().AddTexture("checkboard.jpg");
	ResourceManager::Instance().AddTexture("water.jpg");
	ResourceManager::Instance().AddTexture("coin.jpg");
	ResourceManager::Instance().AddTexture("pool2.png");
	ResourceManager::Instance().AddTexture("smiley.png");
	ResourceManager::Instance().AddTexture("checkpoint.png");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddSound("Checkpoint.wav");
	ResourceManager::Instance().AddMeshFile("funkyshape", 1, "funkyshape.obj");
	ResourceManager::Instance().AddMeshFile("pooltable", 1, "pooltable.obj");
	ResourceManager::Instance().AddMeshFile("platform1", 1, "platform1.obj");
	ResourceManager::Instance().AddMeshFile("platform2", 1, "platform2.obj");
	ResourceManager::Instance().AddMeshFile("platform3", 1, "platform3.obj");
	ResourceManager::Instance().AddMeshFile("platform4", 1, "platform4.obj");
	ResourceManager::Instance().AddMeshFromMethod("quad", 2);
	ResourceManager::Instance().AddSkybox("rustskybox", "rusted_west.jpg", "rusted_east.jpg", "rusted_up.jpg", "rusted_down.jpg", "rusted_south.jpg", "rusted_north.jpg");
	ResourceManager::Instance().AddShader("haze", "PerPixelVert.glsl", "reflectFrag.glsl");
}

void Level4::LoadMap(){
	this->renderer->setSkybox(new Skybox("rustskybox"));

	GameObject* plane = new HazeGameObject(Vector3(0, 1, 0), 0, -50, ResourceManager::Instance().GetShader("haze"),
		ResourceManager::Instance().AddTexture("terrain.jpg"));
	addEventObject(plane);

	GameObject* platform;

	// Start Bottom
	/*platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, 0), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	// Start Right
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(10, 10, 0), 0, Vector3(0.2f, 10, 10), ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);
	// Start Left
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-10, 10, 0), 0, Vector3(0.2f, 10, 10), ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);
	// Start Top
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, 0), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);*/

	platform = new ConcaveGameObject(ResourceManager::Instance().GetShader("Basic"), "platform4", Vector3(0, 0, -20), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	platform = new ConcaveGameObject(ResourceManager::Instance().GetShader("Basic"), "platform3", Vector3(0, 0, -120), 0, 50, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
}

void Level4::LoadObjects(){

}

void Level4::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"), 3);
	addEventObject(player);
	players.push_back(player);
}

void Level4::setObjectiveHUDText(){
	objectiveHUD.SetControlText("Level 3: Gravity Game");
}

std::string Level4::getControlText() const{
	return "Forward - W\nLeft - A\nBackward - S\nRight - D\nJump - Space\nCamera - Left/Right Arrows\nChange Gravity Q/E";
}

