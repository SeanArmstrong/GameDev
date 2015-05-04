#include "CollisionResponse.h"

void CollisionResponse::handleCollision(PlayerGameObject& p, PlaneGameObject& plane){
	PlaneGameObject::PlayerContactAction action = plane.getPlayerAction();
	if (action == PlaneGameObject::PlayerContactAction::Deadly){
		// This collides twice before the reset therefore lives had to be doubled for
		// each player. TODO!
		p.resetPlayerPosition();
		p.looseALife();
		if (p.getPlayerLives() == 0){
			p.setAlive(false);
		}
	}
	else if (action == PlaneGameObject::PlayerContactAction::Reset){
		p.resetPlayerPosition();
	}
	else if (action == PlaneGameObject::PlayerContactAction::Checkpoint){
		// Update reset position
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
	//ResourceManager::Instance().AudioPlaySound("BallClick.wav");

	bool b1HasPlayer = b1.hasLastHitPlayer();
	bool b2HasPlayer = b2.hasLastHitPlayer();
	if (b1HasPlayer && b2HasPlayer){

	}
	else if (b1HasPlayer && !b2HasPlayer){
		b2.setLastHitPlayer(b1.getLastHitPlayer());
	}
	else if (!b1HasPlayer && b2HasPlayer){
		b1.setLastHitPlayer(b2.getLastHitPlayer());
	}
}

void CollisionResponse::handleCollision(PlaneGameObject& plane, PoolBallGameObject& ball){
	if (ball.hasLastHitPlayer()){
		ball.getLastHitPlayer()->incrementScore();
	}
	ball.setExistsInWorld(false);
}

void CollisionResponse::handleCollision(PoolBallGameObject& ball, PlaneGameObject& plane){
	handleCollision(plane, ball);
}


void CollisionResponse::handleCollision(PlayerGameObject& player, PoolBallGameObject& ball){
	ball.setLastHitPlayer(&player);
}

void CollisionResponse::handleCollision(PoolBallGameObject& ball, PlayerGameObject& player){
	handleCollision(player, ball);
}
void CollisionResponse::handleCollision(PlayerGameObject& player, CheckpointGameObject& checkpoint){
	if (!checkpoint.isActivated()){
		btTransform trans;
		checkpoint.getPhysicsObject()->getBody()->getMotionState()->getWorldTransform(trans);
		player.updateStartingPosition(trans.getOrigin());
		ResourceManager::Instance().AudioPlaySound("Checkpoint.wav");
		checkpoint.setActivated(true);
	}
}
void CollisionResponse::handleCollision(CheckpointGameObject& checkpoint, PlayerGameObject& player){
	handleCollision(player, checkpoint);
}

void CollisionResponse::handleCollision(PlayerGameObject& player, EndGameGameObject& endGame){
	// stuff
}
void CollisionResponse::handleCollision(EndGameGameObject& endGame, PlayerGameObject& player){
	handleCollision(player, endGame);
}