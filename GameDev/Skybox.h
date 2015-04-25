#pragma once
#include "RenderObject.h"
#include "SFMLRenderer.h"
#include "ResourceManager.h"

class Skybox
{
public:
	Skybox();
	~Skybox();

	void setViewMatrix(Matrix4 v){
		r.SetViewMatrix(v);
	}

	RenderObject* getRenderObject();
	void Render();

private:

	RenderObject* ro;
	SFMLRenderer r;
};

