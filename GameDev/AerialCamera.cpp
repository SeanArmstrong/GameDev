#include "AerialCamera.h"


AerialCamera::AerialCamera(const bool followPlayer, const Vector3 staticPosition){
	this->followPlayer = followPlayer;
	if (followPlayer){
		this->staticPosition = staticPosition;
	}
}


AerialCamera::~AerialCamera(){
}

Matrix4 AerialCamera::setCam(const PhysicsObject* player){
	btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();
	Matrix4 pos = Matrix4::Translation(bodyPosition);
	Matrix4 offset = Matrix4::Translation(Vector3(0, 200, 0));

	Matrix4 cameraPosition = pos;
	cameraPosition = cameraPosition * offset;

	Vector3 lookingAt(bodyPosition.getX(),
		bodyPosition.getY(),
		bodyPosition.getZ());

	playerLeftVector = Vector3(0, 0, -1);
	playerRightVector = Vector3(0, 0, 1);
	playerForwardVector = Vector3(1, 0, 0);
	playerBackwardVector = Vector3(-1, 0, 0);


	return Matrix4::BuildViewMatrix(cameraPosition.GetPositionVector(), lookingAt, Vector3(0, 0, 1));
}
