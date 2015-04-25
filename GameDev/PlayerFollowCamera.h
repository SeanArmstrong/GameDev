#pragma once
#include "Camera.h"

class PlayerFollowCamera : public Camera
{
public:
	PlayerFollowCamera(const float startRotation = 0);
	virtual ~PlayerFollowCamera();

	virtual Matrix4 setCam(const PhysicsObject* player);

private:

	float rotation;
};

