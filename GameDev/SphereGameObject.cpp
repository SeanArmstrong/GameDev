#include "SphereGameObject.h"


SphereGameObject::SphereGameObject(Shader*s, const Vector3& position, const float mass, const float radius, GLuint t)
{
	ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	ro->SetModelMatrix(Matrix4::Translation(position) * Matrix4::Scale(Vector3(radius, radius, radius)));
	po = new SpherePhysicsObject(ro, position, mass, radius);
}


SphereGameObject::~SphereGameObject()
{
}
