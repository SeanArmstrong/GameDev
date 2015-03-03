  #pragma once
#include "RenderObject.h"
#include "Matrix3.h"


struct Light {
	Vector3 position;
	GLfloat radius;
	Vector3 colour;
};

/*
* Adapted from NCLGL Renderer and OGLRenderer to use SFML
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

	void RemoveRenderObject(const RenderObject &r){
		for (vector<RenderObject*>::const_iterator i; i != renderObjects.end(); ++i){
			if ((*i) == &r){
				renderObjects.erase(i);
			}
		}
	};

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

