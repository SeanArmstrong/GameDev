#pragma once
#include "Camera.h"

class AerialCamera : public Camera
{
public:
	AerialCamera(const bool followPlayer = true, const Vector3& staticPosition = Vector3(0, 200, 0), const Vector3& lookingAt = Vector3(0, 0, 0));
	~AerialCamera();

	virtual Matrix4 setCam(const PhysicsObject* player);

private:

	bool followPlayer;
	Vector3 staticPosition;
	Vector3 lookingAt;
};

