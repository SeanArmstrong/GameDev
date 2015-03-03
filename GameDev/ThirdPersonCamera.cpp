#include "ThirdPersonCamera.h"

ThirdPersonCamera::ThirdPersonCamera(float distance, float height, float mouseSensitivity){
	this->distance = distance;
	this->height = height;
	this->mouseSensitivity = mouseSensitivity;
	this->screenCentre = sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
}

void ThirdPersonCamera::Update(const Vector3& target)
{
	rotation += (screenCentre.x - sf::Mouse::getPosition().x) * mouseSensitivity;
	sf::Mouse::setPosition(screenCentre);

	Matrix4 pos = Matrix4::Translation(-target);
	Matrix4 offset = Matrix4::Translation(-Vector3(0, height, distance));
	Matrix4 rot = Matrix4::Rotation(rotation, Vector3(0, 1, 0));

	cameraPosition = offset * rot * pos;
}