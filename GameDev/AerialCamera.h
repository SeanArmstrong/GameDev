#pragma once
#include "Camera.h"

/**
* @class	AerialCamera
*
* @brief	Top down camera for levels
*			Currently found in pool levels
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class AerialCamera : public Camera
{
public:

	/**
	* @fn	AerialCamera();
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param followPlayer		Sets if the camera follows player sent to setCam Method
	* @param staticPoistion		Sets the static position if the camera does not follow a player
	* @param lookingAt			Sets the static lookingAt position if the camera does not follow player
	*/
	AerialCamera(const bool followPlayer = true, const Vector3& staticPosition = Vector3(0, 200, 0), const Vector3& lookingAt = Vector3(0, 0, 0));
	~AerialCamera();

	// Sets camera to player if not static
	virtual Matrix4 setCam(const PhysicsObject* player);

private:

	bool followPlayer;
	Vector3 staticPosition;
	Vector3 lookingAt;
};

