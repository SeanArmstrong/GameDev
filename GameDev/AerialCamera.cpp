#include "AerialCamera.h"


AerialCamera::AerialCamera(const bool followPlayer, const Vector3& staticPosition, const Vector3& lookingAt){
	this->followPlayer = followPlayer;
	if (!followPlayer){
		this->staticPosition = staticPosition;
		this->lookingAt = lookingAt;
	}
}


AerialCamera::~AerialCamera(){
}

Matrix4 AerialCamera::setCam(const PhysicsObject* player){
	playerLeftVector = Vector3(0, 0, -1);
	playerRightVector = Vector3(0, 0, 1);
	playerForwardVector = Vector3(1, 0, 0);
	playerBackwardVector = Vector3(-1, 0, 0);

	if (followPlayer){
		btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();
		Matrix4 pos = Matrix4::Translation(bodyPosition);
		Matrix4 offset = Matrix4::Translation(Vector3(0, 200, 0));

		Matrix4 cameraPosition = pos;
		cameraPosition = cameraPosition * offset;

		return Matrix4::BuildViewMatrix(cameraPosition.GetPositionVector(), bodyPosition, Vector3(0, 0, 1));
	}
	else{
		return Matrix4::BuildViewMatrix(staticPosition, lookingAt, Vector3(0, 0, 1));
	}
}
