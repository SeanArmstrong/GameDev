#pragma once
#include "GameObject.h"
#include "PoolBallPhysicsObject.h"

/**
* @class	PoolBallGameObject
*
* @brief	Simple Sphere shape which interacts with plane
*			and scores points for users
*			
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PoolBallGameObject : public GameObject
{
public:
	enum Type { Red, Yellow, Black };

	/**
	* @fn	ConvexGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t = 0);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s	If non-null, object shader used when creating the render object
	* @param	position 	The position in space given to the physical object
	* @param	mass	 	The mass of the object
	* @param	radius	 	The radius of the ball
	* @param	type	   	PoolBallGameObject::Type (Red, yellow, black)
	* @param	t		 	The Texture given to the render object
	*/
	PoolBallGameObject(Shader*s, const Vector3& position, const float mass, const float radius, const Type type, GLuint t = 0);
	virtual ~PoolBallGameObject();

	/**
	* @fn	void removeFromGame();
	*
	* @brief	Removes pool ball object from game
	*			Physically and Graphically
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void removeFromGame();

	/**
	* @fn	inline Type getType()
	*
	* @brief	Returns the PoolBallGameObject::Type (Red, yellow, black)
	*			of the pool ball
	*			
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return PoolBallGameObject::Type
	*/
	inline Type getType(){ return type;	}

	/**
	* @fn	inline PlayerGameObject* getLastHitPlayer()
	*
	* @brief	Returns the player that last touched the ball
	*			By direct or indirect contact
	*			
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return PlayerGameObject - Player that last hit the ball
	*/
	inline PlayerGameObject* getLastHitPlayer(){ return lastHitPlayer; }

	/**
	* @fn	inline bool hasLastHitPlayer()
	*
	* @brief	Returns if a player has directly
	*			or indirectly touched the ball
	*
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @return bool if player has affected the ball
	*/
	inline bool hasLastHitPlayer(){ return hasPlayer; }

	/**
	* @fn	void setLastHitPlayer(PlayerGameObject* player);
	*
	* @brief	Sets the lastHitPlayer to param
	*
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param - Player that hit the ball
	*/
	void setLastHitPlayer(PlayerGameObject* player);

	/**
	* @fn	virtual void handleCollision(GameObject& obj);
	*
	* @brief	Handles the collision described by obj.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	obj	The object.
	*/
	virtual void handleCollision(GameObject& obj);

	/**
	* @fn	virtual void handleCollision(PlayerGameObject& player);
	*
	* @brief	Handles the collision between a Pool Ball and a player
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	player	The player.
	*/
	virtual void handleCollision(PlayerGameObject& player);

	/**
	* @fn	virtual void handleCollision(PlaneGameObject& plane);
	*
	* @brief	Handles the collision between a Pool Ball and a plane
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	plane	The plane.
	*/
	virtual void handleCollision(PlaneGameObject& plane);

	/**
	* @fn	virtual void handleCollision(PlaneGameObject& poolball);
	*
	* @brief	Handles the collision between a Pool Ball and a poolball
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	poolball	The poolball.
	*/
	virtual void handleCollision(PoolBallGameObject& poolball);

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}

private:

	// PoolBallGameObject::Type ( Red, Black, Yellow )
	Type type;

	// Player that last hit the ball (direct or indirect)
	PlayerGameObject* lastHitPlayer;
	bool hasPlayer = false;

};

