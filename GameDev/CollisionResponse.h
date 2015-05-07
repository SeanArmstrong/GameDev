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

	/**
	* @fn	static void CollisionResponse::handleCollision(PoolBallGameObject& b1, PoolBallGameObject& b2);
	*
	* @brief	Handles the collision between two pool balls
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	b1  	The Pool Ball 1.
	* @param [in,out]	b2		The Pool Ball 2.
	*/
	static void handleCollision(PoolBallGameObject& b1, PoolBallGameObject& b2);

	/**
	* @fn	static void CollisionResponse::handleCollision(PlaneGameObject& plane, PoolBallGameObject& ball);
	*
	* @brief	Handles the collision between a plane and a ball
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	plane  	The plane
	* @param [in,out]	ball	The ball
	*/
	static void handleCollision(PlaneGameObject& plane, PoolBallGameObject& ball);

	/**
	* @fn	static void CollisionResponse::handleCollision(PoolBallGameObject& ball, PlaneGameObject& plane);
	*
	* @brief	Handles the collision between a plane and a ball
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	ball	The ball
	* @param [in,out]	plane  	The plane
	*/
	static void handleCollision(PoolBallGameObject& ball, PlaneGameObject& plane);

	/**
	* @fn	static void CollisionResponse::handleCollision(PlayerGameObject& player, PoolBallGameObject& ball);
	*
	* @brief	Handles the collision between a player and a ball
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	player 	The player
	* @param [in,out]	ball	The ball
	*/
	static void handleCollision(PlayerGameObject& player, PoolBallGameObject& ball);

	/**
	* @fn	static void CollisionResponse::handleCollision(PoolBallGameObject& ball, PlayerGameObject& player);
	*
	* @brief	Handles the collision between a player and a ball
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	ball	The ball
	* @param [in,out]	player 	The player
	*/
	static void handleCollision(PoolBallGameObject& ball, PlayerGameObject& player);

	/**
	* @fn	static void CollisionResponse::handleCollision(CheckpointGameObject& checkpoint, PlayerGameObject& player);
	*
	* @brief	Handles the collision between a checkpoint and a player
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	checkpoint	The checkpoint
	* @param [in,out]	player 		The player
	*/
	static void handleCollision(CheckpointGameObject& checkpoint, PlayerGameObject& player);

	/**
	* @fn	static void CollisionResponse::handleCollision(PlayerGameObject& player, CheckpointGameObject& checkpoint);
	*
	* @brief	Handles the collision between a checkpoint and a player
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	player 		The player
	* @param [in,out]	checkpoint	The checkpoint
	*/
	static void handleCollision(PlayerGameObject& player, CheckpointGameObject& checkpoint);

	/**
	* @fn	static void CollisionResponse::handleCollision(EndGameGameObject& endGame, PlayerGameObject& player);
	*
	* @brief	Handles the collision between a player and a endGame
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	endGame	The endGame
	* @param [in,out]	player 		The player
	*/
	static void handleCollision(EndGameGameObject& endGame, PlayerGameObject& player);

	/**
	* @fn	static void CollisionResponse::handleCollision(EndGameGameObject& endGame, PlayerGameObject& player);
	*
	* @brief	Handles the collision between a player and a endGame
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	endGame	The endGame
	* @param [in,out]	player 		The player
	*/
	static void handleCollision(PlayerGameObject& player, EndGameGameObject& endGame);


private:

};

