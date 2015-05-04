#include "SphereGameObject.h"


SphereGameObject::SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new SpherePhysicsObject(ro, position, mass, radius);
	this->po->getBody()->setUserPointer((void*)this);
}


SphereGameObject::~SphereGameObject()
{
}
