#include "Level2.h"


Level2::Level2(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r) {
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
	ResourceManager::Instance().AddSound("CoinCollection.wav");
	ResourceManager::Instance().AddSound("LostGame.wav");
	ResourceManager::Instance().AddSound("Clapping.wav");
	ResourceManager::Instance().AddMeshFile("funkyshape", 1, "funkyshape.obj");
	ResourceManager::Instance().AddMeshFile("pooltable", 1, "pooltable.obj");
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
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, 0), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	// Start Right
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(10, 10, 0), 0, 0.2f, 10, 10, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);
	// Start Left
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-10, 10, 0), 0, 0.2f, 10, 10, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);
	// Start Top
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, 0), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);

	// Plats to hide moving
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(7, 10, -10), 0, 3, 10, 0.2f, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(-7, 10, -10), 0, 3, 10, 0.2f, ResourceManager::Instance().AddTexture("brick.jpg"));
	addWorldObject(platform);

	// Level 0
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -20), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -40), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -60), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 0, -80), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("terrain.jpg"));
	addWorldObject(platform);

	// Level 1
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -20), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -40), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -60), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 20, -80), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);

	// Level 2
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -20), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -40), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -60), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 40, -80), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);

	// Level3
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -20), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -40), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -60), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);
	platform = new PlatformGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 60, -80), 0, 10, 0.2f, 10, ResourceManager::Instance().AddTexture("ground.jpg"));
	addWorldObject(platform);

	// Level 0 - Moving Platform
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 9, -20), 0, 0.2f, 9, 10, Vector3(1, 0, 0), 20, 12.25f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 9, -50), 0, 0.2f, 9, 10, Vector3(-1, 0, 0), 20, 12.25f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

	// Level 1 - slides
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -30), 0, 10, 1.0f, 0.2f, Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -50), 0, 10, 1.0f, 0.2f, Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -70), 0, 10, 1.0f, 0.2f, Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 21, -90), 0, 10, 1.0f, 0.2f, Vector3(0, 0, 1), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

	// Lift 1 
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 0, -100), 0, 10, 0.2f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 2, -100), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 2, -100), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 2, -110), 0, 10, 2.0f, 0.2f, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

	// Lift 2
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 20, 20), 0, 10, 0.2f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 22, 20), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 22, 20), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 22, 30), 0, 10, 2.0f, 0.2f, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

	// Lift 3
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 40, -100), 0, 10, 0.2f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 42, -100), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 42, -100), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 42, -110), 0, 10, 2.0f, 0.2f, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

	// Lift 4
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 60, 20), 0, 10, 0.2f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(10, 62, 20), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(-10, 62, 20), 0, 0.2f, 2.0f, 10, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);
	platform = new MovingPlatformGameObject(ResourceManager::Instance().GetShader("BasicRepeating"), Vector3(0, 62, 30), 0, 10, 2.0f, 0.2f, Vector3(0, 1, 0), 20, 5.0f, ResourceManager::Instance().AddTexture("smiley.png"));
	addWorldObject(platform);

}

void Level2::LoadObjects(){

}

void Level2::LoadPlayer(){
	player = new PlayerGameObject(ResourceManager::Instance().GetShader("Basic"), Vector3(0, 10, 0), 2, 1, ResourceManager::Instance().AddTexture("checkboard.jpg"));
	addEventObject(player);
	players.push_back(player);
}