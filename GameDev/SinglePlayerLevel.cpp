#include "SinglePlayerLevel.h"


SinglePlayerLevel::SinglePlayerLevel(sf::RenderWindow* w, SFMLRenderer* r) : Level(w, r), 
hud(w->getSize().x, w->getSize().y)
{
}


SinglePlayerLevel::~SinglePlayerLevel()
{
}

void SinglePlayerLevel::UpdateLevel(){
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

	hud.Update(*player, timer);
}

void SinglePlayerLevel::RenderLevel(){
	renderer->RenderScene();
	hud.Draw(window);
}
void SinglePlayerLevel::GeneralGameLogic(){
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

std::string SinglePlayerLevel::getControlText() const{
	return "Forward - W\nLeft - A\nBackward - S\nRight - D\nJump - Space\nBox Spawn - Space\nCamera - Left/Right Arrows";
}