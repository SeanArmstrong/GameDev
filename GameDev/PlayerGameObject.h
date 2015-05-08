#pragma once
#include "GameObject.h"
#include "PlayerPhysicsObject.h"
#include <SFML\Window.hpp>
#include "PlaneGameObject.h"
#include "CollisionResponse.h"
#include "CubeGameObject.h"
#include "PlayerInputManager.h"

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
	 * @param [in,out]	s		If non-null, object shader used when creating the render object
	 * @param	position 		The position in space given to the physical object
	 * @param	mass	 		The mass of the coin
	 * @param	radius   		The length of a side
	 * @param	t		 		The Texture given to the render object
	 * @param	lives			The number of lives a player starts with
	 * @param	movementSpeed	How fast the player will travel
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
	* @fn	virtual void handleCollision(PoolBallGameObject& poolball);
	*
	* @brief	Handles the collision between a player and a poolball.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	poolball	The poolball.
	*/
	virtual void handleCollision(PoolBallGameObject& poolball);

	/**
	* @fn	virtual void handleCollision(CheckpointGameObject& checkpoint);
	*
	* @brief	Handles the collision between a player and a checkpoint.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	checkpoint	The checkpoint.
	*/
	virtual void handleCollision(CheckpointGameObject& checkpoint);

	/**
	* @fn	virtual void handleCollision(EndGameGameObject& endGame);
	*
	* @brief	Handles the collision between a player and a endGame.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	endGame	The endGame.
	*/
	virtual void handleCollision(EndGameGameObject& endGame);

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

	/**
	* @fn	void setDirectionVectors(const Vector3& forward, onst Vector3& backward, const Vector3& left, const Vector3& right);
	*
	* @brief	Set Direction Vectors for a player so they move
	*			relative to the camera
	* 			
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param forward	The New forward Vector
	* @param backward	The New backward Vector
	* @param left		The New left Vector
	* @param right		The New right Vector
	*/
	void setDirectionVectors(const Vector3& forward,
		const Vector3& backward,
		const Vector3& left,
		const Vector3& right);

	/**
	* @fn	void resetPlayerPosition();
	*
	* @brief	Set Direction Vectors for a player so they move
	*			relative to the camera
	*
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void resetPlayerPosition();

	/**
	* @fn	void setPlayerLives(const int lives);
	*
	* @brief	Sets the players lives
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param lives	The number of lives to give the player
	*/
	void setPlayerLives(const int lives);

	/**
	* @fn	void looseALife();
	*
	* @brief	Removes 1 life from the player
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void looseALife();

	/**
	* @fn	int getPlayerLives() const;
	*
	* @brief	Gets the number of lives a player has
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return	The number of lives to the player has
	*/
	int getPlayerLives() const;


	/**
	* @fn	void updateStartingPosition(const Vector3& newPosition);
	*
	* @brief	Sets the start position to the param
	*			Example use of going through a checkpoint
	*			Reset plane will set to start position
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	position	The new position
	*/
	void updateStartingPosition(const Vector3& newPosition);

	/**
	* @fn	void setEndGoalReached(const bool option);
	*
	* @brief	Sets if the end goal has been reached by the player
	*			sets to option params
	*			
	*			
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	option	Bool to set value to
	*/
	void setEndGoalReached(const bool option);

	/**
	* @fn	inline bool hasReachedEndGoal() 
	*
	* @brief	Returns true if the end goal has been reached
	*			
	*	
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return	if end goal has been reached (BOOL)
	*/
	inline bool hasReachedEndGoal() { return endGoalReached; }

private:
	// Keyboard controls to move player
	int controlSet;

	/* Life Variables */
	bool alive = true;
	unsigned int lives;

	/* Progress Variable */
	int score = 0;
	bool endGoalReached = false;

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

