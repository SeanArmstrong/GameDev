#pragma once
#include "GameObject.h"
#include "ConvexPhysicsObject.h"

/**
* @class	ConvexGameObject
*
* @brief	A Convex game object which inherits GameObject
*			Handles any concave shape based on a its render object mesh
*			Uses a ConvexPhysicsObject which generates the physics object
*			from the mesh vertices.
*			Could be used as generic type but physics collision checks are more
*			complex
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class ConvexGameObject : public GameObject
{
public:

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
	* @param	scale   	scale of object
	* @param	t		 	The Texture given to the render object
	*/
	ConvexGameObject(Shader*s, std::string meshName, Vector3& position, const float mass, const float scale, GLuint t = 0);
	~ConvexGameObject();

	// Unimplemented Collision functions that must be inherited.
	virtual void handleCollision(GameObject& obj){}
	virtual void handleCollision(PlayerGameObject& player){}
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

