#include "CollisionResponse.h"

void CollisionResponse::handleCollision(PlayerGameObject& player, PlaneGameObject& plane){
	if (plane.isDeadly()){
		player.setAlive(false);
	}
}

void CollisionResponse::handleCollision(PlayerGameObject& player, CoinGameObject& coin){
	player.incrementScore();
	ResourceManager::Instance().AudioPlaySound("CoinCollection.wav");
	coin.setExistsInWorld(false);
}


void CollisionResponse::handleCollision(PlaneGameObject& plane, PlayerGameObject& player){
	handleCollision(player, plane);
}

void CollisionResponse::handleCollision(CoinGameObject& coin, PlayerGameObject& player){
	handleCollision(player, coin);
}