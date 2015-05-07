#pragma once
#include "Vector3.h"
#include "Quaternion.h"
#include "PhysicsObject.h"
#include <SFML\Window.hpp>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "GameTimer.h"

/**
 * @class	Camera
 *
 * @brief	Abstract Camera class for all cameras in the levels
 *
 * @author	Sean Armstrong
 * @date	07/05/2015
 */
class Camera
{
public:

	/**
	* @fn	Camera();
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	Camera();
	~Camera();

	// Getters for Player Vectors which allows motion relative to the camera
	inline Vector3 getPlayerForwardVector()		const { return playerForwardVector; }
	inline Vector3 getPlayerBackwardVector()	const { return playerBackwardVector; }
	inline Vector3 getPlayerLeftVector()		const { return playerLeftVector; }
	inline Vector3 getPlayerRightVector()		const { return playerRightVector; }
	inline Vector3 getUpVector()				const { return up; }

	// Set up vector of camera
	inline void setUpVector(const Vector3& up) { this->up = up; }

	// sets newUpVector and begins rotating
	void rotateUpVector(const Vector3& up);

	// Abstract method to set the camera called every frame
	// If rotating call setRotatingUpVector
	virtual Matrix4 setCam(const PhysicsObject* player) = 0;

protected:
	// Interpolate between old up vector a new up vector over 1 second
	void setRotatingUpVector();

	Vector3 playerForwardVector;
	Vector3 playerBackwardVector;
	Vector3 playerLeftVector;
	Vector3 playerRightVector; 
	Vector3 up;

	// Rotation variables
	Vector3 previousUpVector;
	Vector3 newUpVector;
	bool gravityChanging = false;
	float parsedTime;
};

