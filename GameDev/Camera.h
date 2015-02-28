#pragma once
#include "Vector3.h"
#include "Quaternion.h"

class Camera
{
public:
	Camera();
	Camera(const Vector3& pos, const Vector3& forward, const Vector3& up);
	~Camera();
	void Init();

	void move(const Vector3& direction, const float& amount);

	/*
    * This is wrong they shoudl rotate around their own position perhaps?
	*
	*/
	void rotateX(float angle);
	void rotateY(float angle);
	void rotate(float angle, const Vector3& axis);

	// Getters
	Vector3 getPosition() const;
	Vector3 getForward() const;
	Vector3 getUp() const;
	Vector3 getLeft() const;
	Vector3 getRight() const;

	// Setters
	void setPosition(const Vector3& position);
	void setForward(const Vector3& forward);
	void setUp(const Vector3& up);

	const static Vector3 yAxis;
private:
	Vector3 position;
	Vector3 forward;
	Vector3 up;
};

