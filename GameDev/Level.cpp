#include "Level.h"

Level::Level(sf::RenderWindow* w, SFMLRenderer* r) : hud(w->getSize().x, w->getSize().y){
	this->window = w;
	this->renderer = r;
	//sb.Render();
}


Level::~Level(){
	delete player;
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete worldObjects[i];
	}
	for (unsigned int i = 0; i < worldObjects.size(); ++i){
		delete eventObjects[i];
	}
}

void Level::Update(CoreEngine& engine){
	world.getPhysicsWorld()->stepSimulation(GameTimer::getDelta());
	world.callbackChecker(player, eventObjects);
	removeDeletedObjects();

	player->update();

	timer = timer - GameTimer::getDelta();

	GameLogic(engine);

	std::vector<GameObject*>::iterator obj;
	for (obj = worldObjects.begin(); obj < worldObjects.end(); ++obj) {
		(**obj).update();
	}

	for (obj = eventObjects.begin(); obj < eventObjects.end(); ++obj) {
		(**obj).update();
	}
	
	renderer->SetViewMatrix(cam.setPlayerCam(player->getPhysicsObject()/*, rotateAmount*/));
	renderer->UpdateScene(GameTimer::getDelta());

	player->setDirectionVectors(cam.getPlayerForwardVector(),
								cam.getPlayerBackwardVector(),
								cam.getPlayerLeftVector(),
								cam.getPlayerRightVector());

	hud.Update(*player, timer);
}

void Level::Render(){
	//sb.Render();
	renderer->RenderScene();
	hud.Draw(window);
	//world.getPhysicsWorld()->debugDrawWorld();
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
