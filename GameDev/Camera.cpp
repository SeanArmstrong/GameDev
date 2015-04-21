#include "Camera.h"

Camera::Camera(){
	rotation = 0;
}


Camera::~Camera()
{
}

Matrix4 Camera::setPlayerCam(const PhysicsObject* player){
	btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		rotation += 0.5f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		rotation -= 0.5f;
	}

	Matrix4 pos = Matrix4::Translation(bodyPosition);
	Matrix4 offset = Matrix4::Translation(Vector3(0, 10, 30));
	Matrix4 rot = Matrix4::Rotation(rotation, Vector3(0, 1, 0));

	Matrix4 cameraPosition = pos;
	cameraPosition = cameraPosition * rot;
	cameraPosition = cameraPosition * offset;

	Vector3 lookingAt(bodyPosition.getX(),
					  bodyPosition.getY(),
					  bodyPosition.getZ());

	// Left
	playerLeftVector = (cameraPosition.GetPositionVector() - lookingAt).unitVector();

	// Right
	playerRightVector = (lookingAt - cameraPosition.GetPositionVector()).unitVector();

	// Forward
	playerForwardVector = Vector3::Cross(playerLeftVector, Vector3(0, 1, 0));

	// Backward
	playerBackwardVector = Vector3::Cross(playerLeftVector, Vector3(0, -1, 0));


	return Matrix4::BuildViewMatrix(cameraPosition.GetPositionVector(), lookingAt);
}