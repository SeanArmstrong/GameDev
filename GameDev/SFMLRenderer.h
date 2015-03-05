  #pragma once
#include "RenderObject.h"
#include "Matrix3.h"
#include <algorithm>


struct Light {
	Vector3 position;
	GLfloat radius;
	Vector3 colour;
};

/**
 * @class	SFMLRenderer
 *
 * @brief	Adapted from NCLGL OGLRenderer and renderer
 * 			Hols renderobjects to be displayed to the screen
 * 			Also has proj and view matrices for drawing 
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class SFMLRenderer
{
public:
	SFMLRenderer();
	~SFMLRenderer(void);

	virtual void RenderScene();


	virtual void Render(const RenderObject &o);

	virtual void UpdateScene(float msec);

	void AddRenderObject(RenderObject& r) {
		renderObjects.push_back(&r);
	}

	void RemoveRenderObject(RenderObject &r){
		for (unsigned int i = 0; i < renderObjects.size(); ++i){
			if (renderObjects[i] == &r){
				renderObjects.erase(renderObjects.begin() + i);
				break;
			}
		}
	}

	void SetShaderLight(Vector3 position, Vector3 colour, float radius) {
		currentLight.position = position;
		currentLight.colour = colour;
		currentLight.radius = radius;
	}
	
	void UpdateShaderMatrices(GLuint program);

	void			SetProjectionMatrix(Matrix4 m) {
		projMatrix = m;
	}

	void			SetViewMatrix(Matrix4 m) {
		viewMatrix = m;
	}

protected:
	void ApplyShaderLight(GLuint program);

private:
	vector<RenderObject*> renderObjects;
	Matrix4 projMatrix;
	Matrix4 modelMatrix;
	Matrix4 viewMatrix;
	Matrix4 textureMatrix;

	Light currentLight;

	bool	init;			//Did the renderer initialise properly?

	static int		width;
	static int		height;

};

