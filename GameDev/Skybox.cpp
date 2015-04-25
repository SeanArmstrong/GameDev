#include "Skybox.h"


Skybox::Skybox(const std::string skyboxtexture){
	this->ro = new RenderObject(ResourceManager::Instance().AddMeshFromMethod("quad", 2),
		ResourceManager::Instance().AddShader("skybox", "SkyboxVert.glsl", "SkyboxFrag.glsl"),
		ResourceManager::Instance().GetTexture(skyboxtexture));
}


Skybox::~Skybox(){
	delete ro;
}

RenderObject* Skybox::getRenderObject(){
	return ro;
}