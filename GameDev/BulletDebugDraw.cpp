#include "BulletDebugDraw.h"


BulletDebugDraw::BulletDebugDraw()
{
	//r.SetProjectionMatrix(Matrix4::Perspective(1, 100.0f, 1.33f, 45.0f));
	//r.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
}


BulletDebugDraw::~BulletDebugDraw()
{
}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor){
	Mesh* mesh = Mesh::GenerateLine(Vector3(from.getX(), from.getY(), from.getZ()),
		Vector3(to.getX(), to.getY(), to.getZ()),
		Vector3(0,1,1),
		Vector3(0,1,1));

	mesh->Draw();
}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& color){

}

void BulletDebugDraw::drawSphere(const btVector3& p, btScalar radius, const btVector3& color){

}

void BulletDebugDraw::drawTriangle(const btVector3& a, const btVector3& b, const btVector3& c, const btVector3& color, btScalar alpha){

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
