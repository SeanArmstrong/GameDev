#include "PlaneGameObject.h"


PlaneGameObject::PlaneGameObject(Vector3& normal, const float mass, const float distance, Shader*s, GLuint t)
{
	if (s){
		ro = new RenderObject(
			ResourceManager::Instance().AddMeshFromMethod("plane", ResourceManager::MeshGenerationMethods::GENERATE_QUAD), 
			s, 
			t);
	}
	po = new PlanePhysicsObject(NULL, normal, mass, distance);
}


PlaneGameObject::~PlaneGameObject()
{
}
