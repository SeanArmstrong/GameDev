#include "PerimeterEnemyGameObject.h"


PerimeterEnemyGameObject::PerimeterEnemyGameObject(Shader*s, const Vector3& startPosition, const Vector3& startDirection, const float radius,
				const float xDistance, const float zDistance, const float speed, GLuint t)
{
	this->ro = new RenderObject(ResourceManager::Instance().GetMesh("sphere"), s, t);
	this->ro->SetModelMatrix(Matrix4::Translation(startPosition) * Matrix4::Scale(Vector3(radius, radius, radius)));
	this->po = new PerimeterEnemyPhysicsObject(ro, startPosition, radius, xDistance, zDistance, speed, startDirection);
	this->po->getBody()->setUserPointer((void*)this);
}


PerimeterEnemyGameObject::~PerimeterEnemyGameObject()
{
}
