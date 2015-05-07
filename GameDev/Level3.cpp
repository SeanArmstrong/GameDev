#include "Level3.h"


Level3::Level3(sf::RenderWindow* w, SFMLRenderer* r) : SinglePlayerLevel(w, r){
	Initialise();
}


Level3::~Level3()
{
}

void Level3::Initialise(){
	gravityOn = true;
	levelScore = 20;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 60.0f;
	cam = new PlayerFollowCamera();
	setObjectiveHUDText();
	ResourceManager::Instance().AudioPlayAndLoopMusic("space.aiff");
}

void Level3::GameLogic(){

}

void Level3::SetView(){
	renderer->SetShaderLight(Vector3(0, 100.0f, -200.0f), Vector3(1, 1, 1), 10000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void Level3::LoadResources(){
	ResourceManager::Instance();
	ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl");
	ResourceManager::Instance().AddShader("BasicRepeating", "NormalsVert.glsl", "PhongTextureRepeatFrag.glsl");
	ResourceManager::Instance().AddShader("BasicRepeatingLow", "NormalsVert.glsl", "PhongTextureRepeatLowFrag.glsl");
	ResourceManager::Instance().AddShader("Lighting", "NormalsVert.glsl", "PhongFrag.glsl");
	ResourceManager::Instance().AddShader("skybox", "SkyboxVert.glsl", "SkyboxFrag.glsl");
	ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj");
	ResourceManager::Instance().AddMeshFile("sphere", 1, "sphere.obj");
	ResourceManager::Instance().AddMeshFile("coin", 1, "coin3.obj");
	ResourceManager::Instance().AddMeshFile("hollowcylinder", 1, "hollowcylinder.obj");
	ResourceManager::Instance().AddTexture("brick.jpg");
	ResourceManager::Instance().AddTexture("terrain.jpg");
	ResourceManager::Instance().AddTexture("ground.jpg");
	ResourceManager::Instance().AddTexture("checkboard.jpg");
	ResourceManager::Instance().AddTexture("water.jpg");
	ResourceManager::Instance().AddTexture("coin.jpg");
	ResourceManager::Instance().AddTexture("pool2.png");
	ResourceManager::Instance().AddTexture("smiley.png");
	ResourceManager::Instance().AddTexture("checkpoint.png");
	ResourceManager::Instance().AddTexture("metaltile.jpg");
	ResourceManager::Instance().AddTexture("metaltile2.png");
	ResourceManager::Instance().AddTexture("tile.png");
	ResourceManager::Instance().AddMusic("space.aiff");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddSound("Checkpoint.wav");
	ResourceManager::Instance().AddMeshFromMethod("quad", 2);
	ResourceManager::Instance().AddSkybox("spaceskybox", "purplenebula_left.jpg", "purplenebula_right.jpg", "blank.jpg", "purplenebula_top.jpg", "purplenebula_back.jpg", "purplenebula_front.jpg");
	ResourceManager::Instance().AddShader("haze", "PerPixelVert.glsl", "reflectFrag.glsl");
}

void Level3::LoadMap(){
	this->renderer->setSkybox(new Skybox("spaceskybox"));

	GameObject* invisibleGround = new PlaneGameObject(Vector3(0, 1, 0), 0, -50);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	invisibleGround = new PlaneGameObject(Vector3(0, -1, 0), 0, -80);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	invisibleGround = new PlaneGameObject(Vector3(1, 0, 0), 0, -50);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	invisibleGround = new PlaneGameObject(Vector3(-1, 0, 0), 0, -50);
	invisibleGround->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(invisibleGround);

	// Ground Start
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, 0, 0), 0, Vector3(30, 1, 30), ResourceManager::Instance().AddTexture("metaltile2.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(29, 31, -60), 0, Vector3(1, 30, 110), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(-29, 31, -60), 0, Vector3(1, 30, 110), ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Cross
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, 0, -160), 0, Vector3(10, 1, 60), ResourceManager::Instance().AddTexture("metaltile2.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(-20, 0, -160), 0, Vector3(10, 1, 10), ResourceManager::Instance().AddTexture("metaltile2.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(20, 0, -160), 0, Vector3(10, 1, 10), ResourceManager::Instance().AddTexture("metaltile2.png")));

	// Box
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(9, 11, -210), 0, Vector3(1, 10, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(-9, 11, -210), 0, Vector3(1, 10, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, 22, -210), 0, Vector3(10, 1, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, 6, -221), 0, Vector3(10, 6, 1), ResourceManager::Instance().AddTexture("metaltile.jpg")));

	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, 22, -250), 0, Vector3(10, 1, 30), ResourceManager::Instance().AddTexture("tile.png")));
	
	// Cube and Cylinder
	addWorldObject(new CubeGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -265), 0, 1, ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new ConcaveGameObject(ResourceManager::Instance().GetShader("Basic"), "hollowcylinder", Vector3(0, 20, -270), 0, 2, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Final Platform
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, -10, -270), 0, Vector3(2, 1, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeatingLow"), Vector3(0, -10, -250), 0, Vector3(2, 1, 10), ResourceManager::Instance().AddTexture("checkboard.jpg")));

	// End Goal
	GameObject* endGoal = new EndGameGameObject(NULL, Vector3(0, -10, -250), 0, Vector3(2, 2, 5));
	endGoal->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(endGoal);

}

void Level3::LoadObjects(){
}

void Level3::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"), 1);
	addEventObject(player);
	players.push_back(player);
}

void Level3::setObjectiveHUDText(){
	objectiveHUD.SetControlText("Level 3: Gravity Game, Beat the Clock!");
}

std::string Level3::getControlText() const{
	return "Forward - W\nLeft - A\nBackward - S\nRight - D\nJump - Space\nCamera - Left/Right Arrows\nChange Gravity Q/E";
}

void* Level3::operator new(size_t i)
{
	return _mm_malloc(i, 16);
}

void Level3::operator delete(void* p)
{
	_mm_free(p);
}