#include "PlayerFollowCamera.h"


PlayerFollowCamera::PlayerFollowCamera(const float startRotation){
	this->rotation = startRotation;
	up = Vector3(0, 1, 0);
}


PlayerFollowCamera::~PlayerFollowCamera(){
}

Matrix4 PlayerFollowCamera::setCam(const PhysicsObject* player){
	if (gravityChanging){
		setRotatingUpVector();
	}

	btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		rotation += 0.5f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		rotation -= 0.5f;
	}

	Matrix4 pos = Matrix4::Translation(bodyPosition);
	Matrix4 offset = Matrix4::Translation(Vector3(up.x * 10, up.y * 10, 30));

	Matrix4 rot = Matrix4::Rotation(rotation, up);

	Matrix4 cameraPosition = pos;
	cameraPosition = cameraPosition * rot;
	cameraPosition = cameraPosition * offset;

	Vector3 lookingAt(bodyPosition.getX(), bodyPosition.getY(),	bodyPosition.getZ());

	// Left
	playerLeftVector = (cameraPosition.GetPositionVector() - lookingAt).unitVector();
	// Right
	playerRightVector = (lookingAt - cameraPosition.GetPositionVector()).unitVector();
	// Forward
	playerForwardVector = Vector3::Cross(playerLeftVector, up);
	// Backward
	playerBackwardVector = Vector3::Cross(playerRightVector, up);


	return Matrix4::BuildViewMatrix(cameraPosition.GetPositionVector(), lookingAt, up);
}
