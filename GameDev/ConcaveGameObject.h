#pragma once
#include "GameObject.h"
#include "StaticConcavePhysicsObject.h"

/**
* @class	ConcaveGameObject
*
* @brief	A Concave game object which inherits GameObject
*			Handles any convex shape based on a its render object mesh
*			Uses a StaticConcavePhysicsObject which generates the physics object
*			from the mesh vertices. StaticConcavePhysicsObject CAN ONLY BE STATIC!
*			Could be used as generic type but physics collision checks are more
*			complex
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class ConcaveGameObject : public GameObject
{
public:

	/**
	* @fn	ConcaveGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t = 0);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	s	If non-null, object shader used when creating the render object
	* @param	position 	The position in space given to the physical object
	* @param	mass	 	The mass of the coin
	* @param	scale   	scale of object
	* @param	t		 	The Texture given to the render object
	*/
	ConcaveGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t = 0);
	~ConcaveGameObject();


	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

