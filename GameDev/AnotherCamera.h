#pragma once
#include "Vector3.h"
#include "PlayerGameObject.h"

class AnotherCamera
{
public:

	AnotherCamera(PlayerGameObject* player);
	~AnotherCamera();

	static void SetCamera(Vector3 cPosition, float h, float v){

	}

	static void RotateCamera(float h, float v){
	}

	static void SlideCamera(float h, float v){
	}

	static void MoveCamera(float d){
	}

	Vector3 cameraPosition;
	Vector3 cameraTarget;
	Vector3 cameraUpVector;

	float hTheta;
	float vTheta;

	float radius;
	float moveDist;



};

