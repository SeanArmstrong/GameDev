#include "Level2.h"


Level2::Level2(sf::RenderWindow* w, SFMLRenderer* r) : SinglePlayerLevel(w, r) {
	Initialise();
}


Level2::~Level2()
{
}

void Level2::Initialise(){
	gravityOn = false;
	levelScore = 3;

	SetView();
	LoadResources();
	LoadMap();
	LoadObjects();
	LoadPlayer();

	timer = 300.0f;
	cam = new PlayerFollowCamera();
	setObjectiveHUDText();
	ResourceManager::Instance().AudioPlayAndLoopMusic("retro3.wav");
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
	renderer->SetShaderLight(Vector3(0, 200.0f, 0), Vector3(1, 1, 1), 1000.0f);
	renderer->SetProjectionMatrix(Matrix4::Perspective(1, 2000.0f, 1.33f, 45.0f));
}

void Level2::LoadResources(){
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
	ResourceManager::Instance().AddTexture("metaltile.jpg");
	ResourceManager::Instance().AddTexture("metaltile2.png");
	ResourceManager::Instance().AddTexture("checkpoint.jpg");
	ResourceManager::Instance().AddTexture("tile.png");
	ResourceManager::Instance().AddTexture("checkpoint.png");
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddSound("Checkpoint.wav");
	ResourceManager::Instance().AddMusic("retro3.wav");
	ResourceManager::Instance().AddMeshFile("platform1", 1, "platform1.obj");
	ResourceManager::Instance().AddMeshFromMethod("quad", 2);
	ResourceManager::Instance().AddSkybox("rustskybox", "rusted_west.jpg", "rusted_east.jpg", "rusted_up.jpg", "rusted_down.jpg", "rusted_south.jpg", "rusted_north.jpg");
	ResourceManager::Instance().AddShader("haze", "PerPixelVert.glsl", "reflectFrag.glsl");
}

void Level2::LoadMap(){
	this->renderer->setSkybox(new Skybox("rustskybox"));

	GameObject* plane = new HazeGameObject(Vector3(0, 1, 0), 0, -50, ResourceManager::Instance().GetShader("haze"), 
								ResourceManager::Instance().AddTexture("terrain.jpg"));
	addEventObject(plane);
	
	GameObject* platform;

	// Start Bottom
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, 0), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	// Start Right
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(10, 10, 0), 0, Vector3(0.2f, 10, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	// Start Left
	addWorldObject(platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-10, 10, 0), 0, Vector3(0.2f, 10, 10), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	// Start Top
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, 0), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));

	// Plats to hide moving
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(7, 10, -10), 0, Vector3(3, 10, 0.2f), ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-7, 10, -10), 0, Vector3(3, 10, 0.2f), ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Level 0
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -20), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -40), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -60), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -80), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));

	// Level 1
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -20), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -40), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -60), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -80), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	// Level 1 Checkpoint
	addEventObject(new CheckpointGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 22, -83), 0, Vector3(10, 2, 0.1f), 1, ResourceManager::Instance().AddTexture("checkpoint.png"), true), true);

	// Level 2
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, 0), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -20), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -40), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -60), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -80), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	// Level 2 Checkpoint
	addEventObject(new CheckpointGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 42, 3), 0, Vector3(10, 2, 0.1f), 1, ResourceManager::Instance().AddTexture("checkpoint.png"), true), true);

	// Level3
	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -80), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -60), 0, Vector3(10, 0.2f, 10), Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-25, 60, -20), 0, Vector3(5, 0.2f, 10), Vector3(1, 0, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("tile.png")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(25, 60, -20), 0, Vector3(5, 0.2f, 10), Vector3(-1, 0, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("tile.png")));

	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, 20), 0, Vector3(10, 0.2f, 10), Vector3(0, 0, -1), 20, 5.0f, ResourceManager::Instance().AddTexture("tile.png")));

	addWorldObject(new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, 40), 0, Vector3(10, 0.2f, 10), ResourceManager::Instance().AddTexture("checkboard.jpg")));
	
	// Level 3 Checkpoint
	addEventObject(new CheckpointGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 62, -83), 0, Vector3(10, 2, 0.1f), 1, ResourceManager::Instance().AddTexture("checkpoint.png"), true), true);

	// Level 0 - Moving Platform
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 9, -20), 0, Vector3(0.2f, 9, 10), Vector3(1, 0, 0), 20, 12.25f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 9, -50), 0, Vector3(0.2f, 9, 10), Vector3(-1, 0, 0), 20, 12.25f, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Level 1 - slides
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -30), 0, Vector3(10, 1.0f, 0.2f), Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -50), 0, Vector3(10, 1.0f, 0.2f), Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -70), 0, Vector3(10, 1.0f, 0.2f), Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -90), 0, Vector3(10, 1.0f, 0.2f), Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Lift 1 
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -100), 0, Vector3(10, 0.2f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 2, -100), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 2, -100), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 2, -110), 0, Vector3(10, 2.0f, 0.2f), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Lift 2
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 20, 20), 0, Vector3(10, 0.2f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 22, 20), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 22, 20), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 22, 30), 0, Vector3(10.0f, 2.0f, 0.2f), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	// Lift 3
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 40, -100), 0, Vector3(10, 0.2f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 42, -100), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 42, -100), 0, Vector3(0.2f, 2.0f, 10), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));
	addWorldObject(new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 42, -110), 0, Vector3(10, 2.0f, 0.2f), Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("metaltile.jpg")));

	GameObject* endGoal = new EndGameGameObject(NULL, Vector3(0, 66, 40), 0, Vector3(10, 5, 0.1f));
	endGoal->addPhysicsObjectToWorld(*world.getPhysicsWorld());
	eventObjects.push_back(endGoal);
}

void Level2::LoadObjects(){
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-8, 41.5, -5), Vector3(1, 0, 0), 1, 16, 10, 20, ResourceManager::Instance().AddTexture("fire.png")));
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(8, 41.5, -18), Vector3(-1, 0, 0), 1, 16, 10, 20, ResourceManager::Instance().AddTexture("fire.png")));
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-8, 41.5, -31), Vector3(1, 0, 0), 1, 16, 10, 20, ResourceManager::Instance().AddTexture("fire.png")));
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(8, 41.5, -49), Vector3(-1, 0, 0), 1, 16, 10, 20, ResourceManager::Instance().AddTexture("fire.png")));
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-8, 42.5, -64), Vector3(1, 0, 0), 2, 16, 15, 20, ResourceManager::Instance().AddTexture("fire.png")));
	addWorldObject(new PerimeterEnemyGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(8, 42.5, -76), Vector3(-1, 0, 0), 2, 16, 15, 20, ResourceManager::Instance().AddTexture("fire.png")));
}

void Level2::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"), 3);
	addEventObject(player);
	players.push_back(player);
}

void Level2::setObjectiveHUDText(){
	objectiveHUD.SetControlText("Level 2: Get to the Top Floor!");
}

void* Level2::operator new(size_t i)
{
	return _mm_malloc(i, 16);
}

void Level2::operator delete(void* p)
{
	_mm_free(p);
}