#include "MultiPlayerLevel.h"


MultiPlayerLevel::MultiPlayerLevel(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r), hud(w->getSize().x, w->getSize().y)
{
}


MultiPlayerLevel::~MultiPlayerLevel()
{
}

void MultiPlayerLevel::UpdateLevel(){
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

	hud.Update(players, timer, true);

}
void MultiPlayerLevel::RenderLevel(){
	renderer->RenderScene();
	hud.Draw(window);
}

void MultiPlayerLevel::GeneralGameLogic(){
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

	for (unsigned int i = 0; i < players.size(); i++){
		if (!players[i]->isAlive()){
			players[i]->setExistsInWorld(false);
		}
	}

	if (allPlayersDead()){
		ResourceManager::Instance().AudioPlaySound("LostGame.wav");
		endOfGameMessage = "All Players Died!";
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

bool MultiPlayerLevel::allPlayersDead(){
	for (unsigned int i = 0; i < players.size(); i++){
		if (players[i]->isAlive()){
			return false;
		}
	}
	return true;
}

std::string MultiPlayerLevel::getControlText() const {
	return "Player1 WASD\nPlayer2 Arrow Keys";
}