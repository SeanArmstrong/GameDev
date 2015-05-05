#include "Camera.h"

Camera::Camera(){}


Camera::~Camera()
{
}

void Camera::rotateUpVector(const Vector3& newUp){
	previousUpVector = up;
	newUpVector = newUp;
	gravityChanging = true;
	parsedTime = 0;
}

void Camera::setRotatingUpVector(){
	parsedTime += GameTimer::getDelta();
	up = (previousUpVector * (1 - parsedTime) + (newUpVector * parsedTime));
	if (parsedTime > 1){
		up = newUpVector;
		gravityChanging = false;
	}
}