#include "Level.h"

Level::Level(sf::RenderWindow* w, SFMLRenderer* r) : hud(w->getSize().x, w->getSize().y), 
				pauseMenu(w->getSize().x, w->getSize().y){
	this->window = w;
	this->renderer = r;
	setupGravity();
}

Level::~Level(){
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		world.getPhysicsWorld()->removeCollisionObject(worldObjects[i]->getPhysicsObject()->getBody());
		delete worldObjects[i];
	}
	for (unsigned int i = 0; i < eventObjects.size(); ++i){
		world.getPhysicsWorld()->removeCollisionObject(eventObjects[i]->getPhysicsObject()->getBody());
		delete eventObjects[i];
	}
	delete cam;
}

void Level::Update(){
	if (levelState == PAUSED){
		pauseMenu.Update();
	}
	else{
		world.getPhysicsWorld()->stepSimulation(GameTimer::getDelta());
		world.callbackChecker(player, eventObjects);
		removeDeletedObjects();

		timer = timer - GameTimer::getDelta();

		GeneralGameLogic();
		GameLogic();

		std::vector<GameObject*>::iterator obj;
		for (obj = worldObjects.begin(); obj < worldObjects.end(); ++obj) {
			(**obj).update();
		}

		for (obj = eventObjects.begin(); obj < eventObjects.end(); ++obj) {
			(**obj).update();
		}

		renderer->SetViewMatrix(cam->setCam(player->getPhysicsObject()));
		renderer->UpdateScene(GameTimer::getDelta());

		player->setDirectionVectors(cam->getPlayerForwardVector(),
			cam->getPlayerBackwardVector(),
			cam->getPlayerLeftVector(),
			cam->getPlayerRightVector());

		hud.Update(players, timer);
	}
}

void Level::GeneralGameLogic(){
	timeSinceGravityChanged += GameTimer::getDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
		if (gravityOn){
			rotateGravityRight();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		if (gravityOn){
			rotateGravityLeft();
		}
	}

	if (!player->isAlive()){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		endOfGameMessage = "Player Died";
		levelState = LOST;
	}
	if (timer <= 0.0f){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		endOfGameMessage = "Out of Time!";
		levelState = LOST;
	}
	if (player->getScore() == levelScore){
		ResourceManager::Instance().AudioPlaySound("Clapping.wav");
		endOfGameMessage = "Score Limit Reached (Y)";
		levelState = WON;
	}
}

void Level::rotateGravityRight(){
	if (timeSinceGravityChanged > GRAVITY_RESET_TIME){
		timeSinceGravityChanged = 0;
		gravityTracker = (gravityTracker + 1) % 4;
		cam->setUpVector(upVectorDirections[gravityTracker]);
		world.getPhysicsWorld()->setGravity(gravityDirections[gravityTracker]);
	}
}

void Level::rotateGravityLeft(){
	if (timeSinceGravityChanged > GRAVITY_RESET_TIME){
		timeSinceGravityChanged = 0;
		gravityTracker--;
		if (gravityTracker < 0){
			gravityTracker = 3;
		}
		cam->setUpVector(upVectorDirections[gravityTracker]);
		world.getPhysicsWorld()->setGravity(gravityDirections[gravityTracker]);
	}
}

void Level::Render(){
	renderer->RenderScene();
	hud.Draw(window);
	//world.getPhysicsWorld()->debugDrawWorld();
	if (levelState == PAUSED){
		pauseMenu.Draw(window);
	}
}

void Level::removeDeletedObjects(){
	std::set<int> elementsToRemove;

	for (unsigned int i = 0; i < eventObjects.size(); ++i){
		if (!(*eventObjects[i]).getExistsInWorld()){
			elementsToRemove.insert(i);
		}
	}
	std::set<int>::reverse_iterator rit;
	for (rit = elementsToRemove.rbegin(); rit != elementsToRemove.rend(); ++rit){
		(eventObjects[*rit])->removePhysicsObjectFromWorld(*world.getPhysicsWorld());
		(eventObjects[*rit])->removeRenderObjectFromWorld(*renderer);
		eventObjects.erase(eventObjects.begin() + *rit);
	}
}

void Level::addWorldObject(GameObject* g){
	addToWorlds(g);
	worldObjects.push_back(g);
}
void Level::addEventObject(GameObject* g){
	addToWorlds(g);
	eventObjects.push_back(g);
}

void Level::addToWorlds(GameObject* g){
	g->addRenderObjectToWorld(*renderer);
	g->addPhysicsObjectToWorld(*world.getPhysicsWorld());
}

void Level::setupGravity(){
	gravityDirections[0] = btVector3(0, -9.81f, 0);
	gravityDirections[1] = btVector3(9.81f, 0, 0);
	gravityDirections[2] = btVector3(0, 9.81f, 0);
	gravityDirections[3] = btVector3(-9.81f, 0, 0);
	upVectorDirections[0] = btVector3(0, 1, 0);
	upVectorDirections[1] = btVector3(-1, 0, 0);
	upVectorDirections[2] = btVector3(0, -1, 0);
	upVectorDirections[3] = btVector3(1, 0, 0);
	gravityTracker = 0;
}

std::string Level::getEndOfLevelMessage(){
	return endOfGameMessage;
}

void Level::Pause(){
	levelState = PAUSED;
}

void Level::Resume(){
	if (pauseMenu.GetElementIndex() == 0){
		levelState = PLAYING;
	}
	else{
		levelState = QUITTING;
	}
}