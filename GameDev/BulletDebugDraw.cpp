#include "BulletDebugDraw.h"


BulletDebugDraw::BulletDebugDraw()
{
}


BulletDebugDraw::~BulletDebugDraw()
{
}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor){
	//std::cout << "DrawLine" << std::endl;
	Mesh* mesh = Mesh::GenerateLine(Vector3(from.getX(), from.getY(), from.getZ()),
		Vector3(to.getX(), to.getY(), to.getZ()),
		Vector3(1,1,1),
		Vector3(1,1,1));

	Shader *s = ResourceManager::Instance().AddShader("basic", "basicVert.glsl", "textureFrag.glsl");
	RenderObject* ro = new RenderObject(mesh, s);

	SFMLRenderer r;
	r.Render(*ro);
}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& color){
	drawLine(from, to, color, color);
}

void BulletDebugDraw::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color){

}
void BulletDebugDraw::reportErrorWarning(const char* warningString){

}
void BulletDebugDraw::draw3dText(const btVector3& location, const char* textString){

}
void BulletDebugDraw::setDebugMode(int debugMode){
	m_debugMode = debugMode;
}
