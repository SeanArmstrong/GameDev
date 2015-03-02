#include "Camera.h"

const Vector3 Camera::yAxis = Vector3(0, 1, 0);

Camera::Camera(){
	Camera(Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(0, 1, 0));
}

Camera::Camera(const Vector3& position, const Vector3& forward, const Vector3& up){
	this->position = position;
	this->forward = forward;
	this->up = up;

	this->forward.Normalise();
	this->up.Normalise();
}

Camera::~Camera()
{
}

void Camera::Init(){
	this->position = Vector3(0, 0, 0);
	this->forward = Vector3(0, 0, 1);
	this->up = Vector3(0, 1, 0);

	this->forward.Normalise();
	this->up.Normalise();
}

void Camera::rotate(float angle, const Vector3& axis){
	float sinHalfAngle = (float)sin(DegToRad(angle / 2));
	float cosHalfAngle = (float)cos(DegToRad(angle / 2));

	float rX = axis.x * sinHalfAngle;
	float rY = axis.y * sinHalfAngle;
	float rZ = axis.z * sinHalfAngle;
	float rW = cosHalfAngle;

	Quaternion rotation = Quaternion(rX, rY, rZ, rW);
	Quaternion conjugate = rotation.Conjugate();

	Quaternion w = conjugate * forward * rotation;

	forward.x = w.x;
	forward.y = w.y;
	forward.z = w.z;
}

void Camera::move(const Vector3& direction, const float& amount){
	position = position + (direction * amount);
}

void Camera::rotateX(float angle){
	Vector3 horizontalAxis = Vector3::Cross(yAxis, forward);
	horizontalAxis.Normalise();

	rotate(angle, horizontalAxis);
	forward.Normalise();

	up = Vector3::Cross(forward, horizontalAxis);
	up.Normalise();
}

void Camera::rotateY(float angle){
	Vector3 horizontalAxis = Vector3::Cross(yAxis, forward);
	horizontalAxis.Normalise();
	
	rotate(angle, yAxis);
	forward.Normalise();

	up = Vector3::Cross(forward, horizontalAxis);
	up.Normalise();
}

// Getters
Vector3 Camera::getPosition() const {
	return position;
}

Vector3 Camera::getForward() const {
	return forward;
}

Vector3 Camera::getUp() const {
	return up;
}

Vector3 Camera::getLeft() const {
	return (Vector3::Cross(up, forward)).unitVector();
}

Vector3 Camera::getRight() const {
	return (Vector3::Cross(forward, up)).unitVector();
}

// Setters
void Camera::setPosition(const Vector3& position){
	this->position = position;
}

void Camera::setForward(const Vector3& forward){
	this->forward = forward;
}

void Camera::setUp(const Vector3& up){
	this->up = up;
}

Matrix4 Camera::setPlayerCam(const PhysicsObject* player){
	btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();

	Vector3 from(bodyPosition.getX(),
				 bodyPosition.getY() + 10,
				 bodyPosition.getZ() + 30);

	Vector3 lookingAt(bodyPosition.getX(),
					  bodyPosition.getY(),
					  bodyPosition.getZ());

	return Matrix4::BuildViewMatrix(from, lookingAt);
}

Matrix4 Camera::setPlayerCam(const PhysicsObject* player, const float rotateAmount){
	/*btVector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();
	float mouseX = mouse.x;
	float mouseY = mouse.y;

	Vector3 from(bodyPosition.getX(),
		bodyPosition.getY() + 10,
		bodyPosition.getZ() + 30);

	Vector3 lookingAt(bodyPosition.getX(),
		bodyPosition.getY(),
		bodyPosition.getZ());

	return Matrix4::BuildViewMatrix(from, lookingAt);*/

	Vector3 bodyPosition = player->getBody()->getWorldTransform().getOrigin();
	Vector3 camFocusVector = position - bodyPosition;
	Matrix4 pos;
	pos.SetPositionVector(camFocusVector);

	Matrix4 rotation = Matrix4::Rotation(1.0f, Vector3(0, 1, 0));
	Matrix4 final = pos * rotation;

	final.GetPositionVector();
	// have a lookm to fix this
	// also try new cam and make sure i used the correct Matrix build
	return Matrix4::BuildViewMatrix(final.GetPositionVector(), bodyPosition);
	
}
