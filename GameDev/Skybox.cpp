#include "Skybox.h"


Skybox::Skybox(){
	this->ro = new RenderObject(ResourceManager::Instance().AddMeshFile("cube", 1, "cube.obj"),
		ResourceManager::Instance().AddShader("Basic", "basicvert.glsl", "textureFrag.glsl"),
		ResourceManager::Instance().AddTexture("brick.jpg"));

}


Skybox::~Skybox(){
	delete ro;
}

RenderObject* Skybox::getRenderObject(){
	return ro;
}

void Skybox::Render(){
	glDepthMask(0);
	r.RenderSkybox(*ro);
	glDepthMask(GL_TRUE);
}