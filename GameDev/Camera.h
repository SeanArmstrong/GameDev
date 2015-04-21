#pragma once
#include "Vector3.h"
#include "Quaternion.h"
#include "PhysicsObject.h"
#include <SFML\Window.hpp>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

/**
 * @class	Camera
 *
 * @brief	*****UNUSED*****
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

class Camera
{
public:
	Camera();
	~Camera();

	inline Vector3 getPlayerForwardVector()		const { return playerForwardVector; }
	inline Vector3 getPlayerBackwardVector()	const { return playerBackwardVector; }
	inline Vector3 getPlayerLeftVector()		const { return playerLeftVector; }
	inline Vector3 getPlayerRightVector()		const { return playerRightVector; }

	Matrix4 setPlayerCam(const PhysicsObject* player);

private:

	Vector3 playerForwardVector;
	Vector3 playerBackwardVector;
	Vector3 playerLeftVector;
	Vector3 playerRightVector; 

	float rotation;
};

