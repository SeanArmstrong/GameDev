#pragma once
#include "RenderObject.h"
#include "ResourceManager.h"

class Skybox
{
public:
	Skybox(){};
	Skybox(const std::string skyboxtexture);
	~Skybox();

	RenderObject* getRenderObject();

private:
	RenderObject* ro;
};

