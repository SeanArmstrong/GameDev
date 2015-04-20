#pragma once
#include "Vector3.h"
#include "Quaternion.h"
#include "PhysicsObject.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

/**
 * @class	Camera
 *
 * @brief	*****UNUSED*****
 *
 * @author	Sean Armstrong
 * @date	08/03/2015
 */

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

	Matrix4 setPlayerCam(const PhysicsObject* player);

	Matrix4 setPlayerCam(const PhysicsObject* player, const float rotateAmount);

	const static Vector3 yAxis;

private:
	Vector3 position;
	Vector3 forward;
	Vector3 up;
};

