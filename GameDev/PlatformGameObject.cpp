#include "PlatformGameObject.h"

PlatformGameObject::PlatformGameObject(Shader*s, const Vector3& position, const float mass, 
						const Vector3& lengthHeightDepth, GLuint t) {

	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("cube"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(lengthHeightDepth));
	this->po = new PlatformPhysicsObject(ro, position, mass, lengthHeightDepth);
	this->po->getBody()->setUserPointer((void*)this);
}


PlatformGameObject::~PlatformGameObject()
{
}