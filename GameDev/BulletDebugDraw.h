#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "RenderObject.h"
#include <LinearMath\btIDebugDraw.h>
#include "SFMLRenderer.h"
#include "ResourceManager.h"

/**
 * @class	BulletDebugDraw
 *
 * @brief	Extends btIDebugDraw. A abstract class that enables drawing of physical
 * 			objects to the screen
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class BulletDebugDraw : public btIDebugDraw
{
 int m_debugMode;

public:
	BulletDebugDraw();
	virtual ~BulletDebugDraw();

	/**
	 * @fn	virtual void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);
	 *
	 * @brief	Draw the line for the physical object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	from	 	Starting vector
	 * @param	to		 	Ending Vector
	 * @param	fromColor	Starting colour
	 * @param	toColor  	Ending colour
	 */

	virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);

	virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);

	virtual void drawSphere(const btVector3& p, btScalar radius, const btVector3& color);

	virtual void drawTriangle(const btVector3& a, const btVector3& b, const btVector3& c, const btVector3& color, btScalar alpha);

	virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);

	virtual void reportErrorWarning(const char* warningString);

	virtual void draw3dText(const btVector3& location, const char* textString);

	virtual void setDebugMode(int debugMode);
	virtual int getDebugMode() const { return m_debugMode; }

	//SFMLRenderer r;
	//Shader *s = ResourceManager::Instance().AddShader("basic", "basicVert.glsl", "textureFrag.glsl");
};

