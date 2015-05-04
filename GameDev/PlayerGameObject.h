#pragma once
#include "GameObject.h"
#include "PlayerPhysicsObject.h"
#include <SFML\Window.hpp>
#include "PlaneGameObject.h"
#include "CollisionResponse.h"
#include "CubeGameObject.h"
#include "InputManager.h"

/**
 * @class	PlayerGameObject
 *
 * @brief	A player game object which inherits GameObject
 * 			This is the playable character within the game
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class PlayerGameObject : public GameObject
{
public:

	/**
	 * @fn	PlayerGameObject::PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	s	If non-null, object shader used when creating the render object
	 * @param	position 	The position in space given to the physical object
	 * @param	mass	 	The mass of the coin
	 * @param	radius   	The length of a side
	 * @param	t		 	The Texture given to the render object
	 */

	PlayerGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t, const unsigned int lives = 1, const float movementSpeed = 20.0f);
	~PlayerGameObject();

	/**
	 * @fn	Vector3 PlayerGameObject::getPosition() const;
	 *
	 * @brief	Gets the position of the player
	 * 			from the physical transform
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	The position.
	 */

	Vector3 getPosition() const;

	/**
	 * @fn	bool PlayerGameObject::isAlive() const;
	 *
	 * @brief	Query if this player is alive.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	true if alive, false if not.
	 */

	bool isAlive() const;

	/**
	 * @fn	int PlayerGameObject::getScore() const;
	 *
	 * @brief	Gets the score of the player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	The score.
	 */

	int getScore() const;

	/**
	 * @fn	void PlayerGameObject::setPosition(Vector3 view);
	 *
	 * @brief	Sets a position of the player by
	 * 			setting the physical object transform
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	view	The view.
	 */

	void setPosition(Vector3 view);

	/**
	 * @fn	void PlayerGameObject::setAlive(bool status);
	 *
	 * @brief	Sets the alive status of the player
	 * 			Default is true so usually set to false
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	status	true to status.
	 */

	void setAlive(bool status);

	/**
	 * @fn	void PlayerGameObject::setScore(int newScore);
	 *
	 * @brief	Sets the score of the player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	newScore	The new score.
	 */

	void setScore(int newScore);

	/**
	 * @fn	void PlayerGameObject::increaseScore();
	 *
	 * @brief	Increments teh score of the player
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void incrementScore();

	/**
	 * @fn	virtual void PlayerGameObject::update();
	 *
	 * @brief	Updates the player.
	 * 			Applies movement from key input
	 * 			and allows the player to jump/shoot 
	 * 			with a inteval checker
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void update();

	/**
	 * @fn	virtual void PlayerGameObject::handleCollision(GameObject& obj);
	 *
	 * @brief	Handles the collision described by obj.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	obj	The object.
	 */

	virtual void handleCollision(GameObject& obj);

	/**
	 * @fn	virtual void PlayerGameObject::handleCollision(PlayerGameObject& player);
	 *
	 * @brief	Handles the collision between 2 players.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	player	The player.
	 */

	virtual void handleCollision(PlayerGameObject& player);

	/**
	 * @fn	virtual void PlayerGameObject::handleCollision(PlaneGameObject& plane);
	 *
	 * @brief	Handles the collision between a player and a plane.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	plane	The plane.
	 */

	virtual void handleCollision(PlaneGameObject& plane);

	/**
	 * @fn	virtual void PlayerGameObject::handleCollision(CoinGameObject& coin);
	 *
	 * @brief	Handles the collision between a player and a coin.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	coin	The coin.
	 */

	virtual void handleCollision(CoinGameObject& coin);

	/**
	 * @fn	GameObject* PlayerGameObject::spawnCube();
	 *
	 * @brief	Creates a new cube in from of the player
	 * 			Returns the newly created cube so that
	 * 			it can be added to the physical world
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else a GameObject*.
	 */

	GameObject* spawnCube();

	virtual void handleCollision(PoolBallGameObject& poolball);

	void setDirectionVectors(const Vector3& forward,
		const Vector3& backward,
		const Vector3& left,
		const Vector3& right);

	void resetPlayerPosition();

	void setPlayerLives(const int lives);
	void looseALife();
	int getPlayerLives() const;

private:
	int controlSet;

	/* Life Variables */
	bool alive = true;
	unsigned int lives;

	/* Progress Variable */
	int score = 0;

	/* Movement variables */
	Vector3 forward;
	Vector3 backward;
	Vector3 left;
	Vector3 right;
	Vector3 jumpDirection;
	float movementSpeed;
	bool jumping;
	const float JUMPRESETTIME = 1.0f;
	float timeSinceJumped;
	Vector3 startingPosition;

	/* Weapon options */
	const float SHOOT_DELAY = 2.0f;
	float timeSinceShot = 0;
};

