#include "CollisionResponse.h"

PlayerGameObject* CollisionResponse::player;

void CollisionResponse::setPlayer(PlayerGameObject* p){
	player = p;
}

void CollisionResponse::handleCollision(PlayerGameObject& p, PlaneGameObject& plane){
	if (plane.isDeadly()){
		p.setAlive(false);
	}
}

void CollisionResponse::handleCollision(PlayerGameObject& p, CoinGameObject& coin){
	p.incrementScore();
	ResourceManager::Instance().AudioPlaySound("CoinCollection.wav");
	coin.setExistsInWorld(false);
}


void CollisionResponse::handleCollision(PlaneGameObject& plane, PlayerGameObject& p){
	handleCollision(p, plane);
}

void CollisionResponse::handleCollision(CoinGameObject& coin, PlayerGameObject& p){
	handleCollision(p, coin);
}

void CollisionResponse::handleCollision(PoolBallGameObject& b1, PoolBallGameObject& b2){
	ResourceManager::Instance().AudioPlaySound("BallClick.wav");
}

void CollisionResponse::handleCollision(PlaneGameObject& plane, PoolBallGameObject& ball){
	/*if (ball.getType == PoolBallGameObject::Type::Yellow){

	}
	else if (ball.getType == PoolBallGameObject::Type::Red){

	}
	else { //black

	}*/
	player->incrementScore();
	ball.setExistsInWorld(false);
}

void CollisionResponse::handleCollision(PoolBallGameObject& ball, PlaneGameObject& plane){
	handleCollision(plane, ball);
}