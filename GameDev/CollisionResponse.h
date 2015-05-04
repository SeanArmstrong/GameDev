#pragma once

#include "ResourceManager.h"
#include "GameObject.h"
#include "PlayerGameObject.h"
#include "CoinGameObject.h"
#include "PoolBallGameObject.h"
#include "CheckpointGameObject.h"

/**
 * @class	CollisionResponse
 *
 * @brief	A collision response system for game objects
 * 			Static methods only
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CollisionResponse
{
public:

	static void setPlayer(PlayerGameObject* p);

	/**
	 * @fn	static void CollisionResponse::handleCollision(PlayerGameObject& player, PlaneGameObject& plane);
	 *
	 * @brief	Handles the collision between a player and a plane
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 * @param [in,out]	plane 	The plane.
	 */

	static void handleCollision(PlayerGameObject& player, PlaneGameObject& plane);

	/**
	 * @fn	static void CollisionResponse::handleCollision(PlayerGameObject& player, CoinGameObject& coin);
	 *
	 * @brief	Handles the collision between a player and a coin
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 * @param [in,out]	coin  	The coin.
	 */

	static void handleCollision(PlayerGameObject& player, CoinGameObject& coin);

	/**
	 * @fn	static void CollisionResponse::handleCollision(PlaneGameObject& plane, PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between a plane and a player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane 	The plane.
	 * @param [in,out]	player	The player.
	 */

	static void handleCollision(PlaneGameObject& plane, PlayerGameObject& player);

	/**
	 * @fn	static void CollisionResponse::handleCollision(CoinGameObject& coin, PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between a coin and a player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin  	The coin.
	 * @param [in,out]	player	The player.
	 */

	static void handleCollision(CoinGameObject& coin, PlayerGameObject& player);
	static void handleCollision(PoolBallGameObject& b1, PoolBallGameObject& b2);
	static void handleCollision(PlaneGameObject& plane, PoolBallGameObject& ball);
	static void handleCollision(PoolBallGameObject& ball, PlaneGameObject& plane);
	static void handleCollision(PlayerGameObject& player, PoolBallGameObject& ball);
	static void handleCollision(PoolBallGameObject& ball, PlayerGameObject& player);
	static void handleCollision(CheckpointGameObject& checkpoint, PlayerGameObject& player);
	static void handleCollision(PlayerGameObject& player, CheckpointGameObject& checkpoint);
	static void handleCollision(EndGameGameObject& endGame, PlayerGameObject& player);
	static void handleCollision(PlayerGameObject& player, EndGameGameObject& endGame);


private:

};

