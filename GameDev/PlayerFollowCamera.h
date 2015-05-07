#pragma once
#include "Camera.h"

/**
* @class	AerialCamera
*
* @brief	Camera set behind given player to setCam Method
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class PlayerFollowCamera : public Camera
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
	* @param startRotation		sets the intial rotation around the player
	*/
	PlayerFollowCamera(const float startRotation = 0);
	virtual ~PlayerFollowCamera();

	// updates camera to player position and updates rotation
	virtual Matrix4 setCam(const PhysicsObject* player);

private:

	float rotation;
};

