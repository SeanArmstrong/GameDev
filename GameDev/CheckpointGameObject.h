#pragma once
#include "GameObject.h"
#include "PlatformPhysicsObject.h"
#include "CollisionResponse.h"

/**
* @class	CheckpointGameObject
*
* @brief	Checkpoint game object inherits from Game Object
*			Sets the player position to its position on collision
*			Can also give lives to player
*			When colliding with a player the checkpoint is disabled
*			
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class CheckpointGameObject : public GameObject
{
public:

	/**
	* @fn	CheckpointGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, const int numberOfLives = 0,
						GLuint t = 0, const bool hasRenderObject = false);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s				If non-null, object shader used when creating the render object
	* @param	position 				The position in space given to the physical object
	* @param	mass	 				The mass of the object
	* @param	lengthHeightDepth   	Dimensions
	* @param	numberOfLives   		How many lives it gives the player
	* @param	t		 				The Texture given to the render object
	* @param	hasRenderObject			Sets if it has a graphical representation
	*/
	CheckpointGameObject(Shader*s, const Vector3& position, const float mass, const Vector3& lengthHeightDepth, const int numberOfLives = 0, GLuint t = 0, const bool hasRenderObject = false);
	virtual ~CheckpointGameObject();

	/**
	* @fn	virtual void handleCollision(GameObject& obj);
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
	* @fn	virtual void handleCollision(PlayerGameObject& player);
	*
	* @brief	Handles the collision between checkpoint and player.
	*
	* @author	Sean Armstrong
	* @date	05/03/2015
	*
	* @param [in,out]	player	The player.
	*/
	virtual void handleCollision(PlayerGameObject& player);

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}

	// Checks if the checkpoint is active
	bool isActivated();

	// Sets activation state to bool
	void setActivated(bool option);

	// Returns the number of lives to give a player
	int getNumberOfLives();

private:

	bool activated;
	int numberOfLives;
};

