#include "MovingPlatformGameObject.h"


MovingPlatformGameObject::MovingPlatformGameObject(Shader*s, const Vector3& position, const float mass,
	const Vector3& lengthHeightDepth, const Vector3& direction,
	const float distance, const float speed, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(lengthHeightDepth));
	this->po = new MovingPlatformPhysicsObject(ro, position, mass, lengthHeightDepth, direction, distance, speed);
	this->po->getBody()->setUserPointer((void*)this);
}


MovingPlatformGameObject::~MovingPlatformGameObject()
{
}
