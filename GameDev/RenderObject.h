#pragma once
#include "Matrix4.h"
#include "Mesh.h"
#include "Shader.h"
#include "ResourceManager.h"


class RenderObject	{
public:
	RenderObject(void);
	RenderObject(Mesh*m, Shader*s, GLuint t = 0);
	~RenderObject(void);

	void Intialize(Mesh* m, Shader* s, GLuint t = 0);

	Mesh*	GetMesh()	const			{return mesh;}
	void	SetMesh(Mesh*m)				{mesh = m;}

	Shader* GetShader()		const		{return shader; }
	void	SetShader(Shader*s)			{shader = s;}

	GLuint	GetTexture0()		const	{ return tex0; }
	GLuint	GetTexture1()		const	{ return tex1; }
	GLuint	GetTexture2()		const	{ return tex2; }
	void	SetTexture0(GLuint tex)		{ this->tex0 = tex; }
	void	SetTexture1(GLuint tex)		{ this->tex1 = tex; }
	void	SetTexture2(GLuint tex)		{ this->tex2 = tex; }
	void	SetCubeMap(GLuint tex)		{ this->cubemap = tex; }

	void	SetModelMatrix(Matrix4 mat) {
		modelMatrix = mat;
	}
	Matrix4 GetModelMatrix()	const	{return modelMatrix;}

	virtual void Update(float msec);

	virtual void Draw() const;

	virtual void DrawSkybox() const;

	//virtual void Update(float msec);

	void	AddChild(RenderObject &child) {
		children.push_back(&child);
		child.parent = this;
	}

	Matrix4 GetWorldTransform() const {
		return worldTransform;
	}

	const vector<RenderObject*>& GetChildren() const  {
		return children;
	}

protected:
	Mesh*	mesh;
	Shader*	shader;
	GLuint cubemap;

	GLuint tex0;
	GLuint tex1;
	GLuint tex2;

	Matrix4 modelMatrix;
	Matrix4 worldTransform;

	RenderObject*			parent;
	vector<RenderObject*>	children;
};

