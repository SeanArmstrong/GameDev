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
	inline Vector3 getUpVector()				const { return up; }

	inline void setUpVector(const Vector3& up) { this->up = up; }
	virtual Matrix4 setCam(const PhysicsObject* player) = 0;
	Matrix4 setAboveCam(const PhysicsObject* player);

protected:

	Vector3 playerForwardVector;
	Vector3 playerBackwardVector;
	Vector3 playerLeftVector;
	Vector3 playerRightVector; 
	Vector3 up;
};

