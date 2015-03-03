#pragma once
#include <SFML/Window.hpp>
#include "SFMLRenderer.h"
#include "Vector3.h"


class ThirdPersonCamera
{
public:
	ThirdPersonCamera(float distance, float height, float mouseSensitivity = 0.1f);
	~ThirdPersonCamera();

	void Update(const Vector3& target);

	float distance;
	float height;
	Matrix4 cameraPosition;


private:
	sf::Vector2i screenCentre;
	float rotation = 0;
	float mouseSensitivity = 0.1f;
};