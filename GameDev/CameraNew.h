/**
 * @file	CameraNew.h
 *
 * @brief	Unused.
 */

#pragma once
#include "Vector3.h"

class CameraNew
{
public:

	// Our camera constructor
	CameraNew();
	~CameraNew();

	// This changes the position, view, and up vector of the camera.
	// This is primarily used for initialization
	void PositionCamera(Vector3 position, Vector3 view, Vector3 up = Vector3(0,1,0));

	// This rotates the camera's view around the position using axis-angle rotation
	void RotateView(float angle, float X, float Y, float Z);

	// This rotates the camera around a point (i.e. your character).
	// vCenter is the point that we want to rotate the position around.
	// Like the other rotate function, the x, y and z is the axis to rotate around.
	void RotateAroundPoint(Vector3 center, float angle, float x, float y, float z);

	// This will move the camera forward or backward depending on the speed
	void MoveCamera(float speed);
	Vector3 position;
	Vector3 view;
	Vector3 upVector;
private:

};

