#include "CameraNew.h"


CameraNew::CameraNew(){	
	position = Vector3(0.0, 0.0, 0.0);
	view = Vector3(0.0, 1.0, 0.5);
	upVector = Vector3(0.0, 0.0, 1.0);
}


CameraNew::~CameraNew(){
}

void CameraNew::PositionCamera(Vector3 position, Vector3 view, Vector3 up){
	this->position = position;
	this->view = view;
	this->upVector = up;
}

void CameraNew::RotateView(float angle, float x, float y, float z){
	Vector3 newView;

	// Get the view vector (The direction we are facing)
	Vector3 vView = view - position;

	// Calculate the sine and cosine of the angle once
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	newView.x = (cosTheta + (1 - cosTheta) * x * x)		* vView.x;
	newView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vView.y;
	newView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vView.z;

	// Find the new y position for the new rotated point
	newView.y = ((1 - cosTheta) * x * y + z * sinTheta)	* vView.x;
	newView.y += (cosTheta + (1 - cosTheta) * y * y)		* vView.y;
	newView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vView.z;

	// Find the new z position for the new rotated point
	newView.z = ((1 - cosTheta) * x * z - y * sinTheta)	* vView.x;
	newView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vView.y;
	newView.z += (cosTheta + (1 - cosTheta) * z * z)		* vView.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated view of our camera.
	view = position + newView;
}

void CameraNew::RotateAroundPoint(Vector3 center, float angle, float x, float y, float z)
{
	Vector3 newPosition;

	// To rotate our position around a point, what we need to do is find
	// a vector from our position to the center point we will be rotating around.
	// Once we get this vector, then we rotate it along the specified axis with
	// the specified degree.  Finally the new vector is added center point that we
	// rotated around (vCenter) to become our new position.  That's all it takes.

	// Get the vVector from our position to the center we are rotating around
	Vector3 vPos = position - center;

	// Calculate the sine and cosine of the angle once
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	newPosition.x = (cosTheta + (1 - cosTheta) * x * x)		* vPos.x;
	newPosition.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vPos.y;
	newPosition.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vPos.z;

	// Find the new y position for the new rotated point
	newPosition.y = ((1 - cosTheta) * x * y + z * sinTheta)	* vPos.x;
	newPosition.y += (cosTheta + (1 - cosTheta) * y * y)		* vPos.y;
	newPosition.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vPos.z;

	// Find the new z position for the new rotated point
	newPosition.z = ((1 - cosTheta) * x * z - y * sinTheta)	* vPos.x;
	newPosition.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vPos.y;
	newPosition.z += (cosTheta + (1 - cosTheta) * z * z)		* vPos.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated position of our camera.
	position = center + newPosition;
}

void CameraNew::MoveCamera(float speed)
{
	Vector3 vVector = view - position;

	position.x += vVector.x * speed;
	position.z += vVector.z * speed;
	view.x += vVector.x * speed;
	view.z += vVector.z * speed;
}
