#pragma once
#include "RenderObject.h"
#include "SFMLRenderer.h"
#include "ResourceManager.h"

class Skybox
{
public:
	Skybox();
	~Skybox();

	RenderObject* getRenderObject();
	void Render();

private:

	RenderObject* ro;
	SFMLRenderer r;
};

