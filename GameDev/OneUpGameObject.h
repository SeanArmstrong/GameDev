#pragma once
#include "GameObject.h"

/**
* @class	OneUpGameObject

******UNIMPLEMENTED********
*
* @brief	TODO - Gives life to player
*			TODO - Create Parent Collectable Class for coin and one up?
*			
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class OneUpGameObject : public GameObject
{
public:
	OneUpGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t = 0);
	virtual ~OneUpGameObject();

	virtual void handleCollision(GameObject& obj);
	virtual void handleCollision(PlayerGameObject& player);
	virtual void handleCollision(PlaneGameObject& plane){}
	virtual void handleCollision(CoinGameObject& coin){}
	virtual void handleCollision(PoolBallGameObject& poolball){}
	virtual void handleCollision(CheckpointGameObject& checkpoint){}
	virtual void handleCollision(EndGameGameObject& endGame){}
};

