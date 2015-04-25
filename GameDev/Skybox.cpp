#include "Skybox.h"


Skybox::Skybox(){
	this->ro = new RenderObject(ResourceManager::Instance().AddMeshFromMethod("quad", 2),
		ResourceManager::Instance().AddShader("skybox", "SkyboxVert.glsl", "SkyboxFrag.glsl"),
		ResourceManager::Instance().AddSkybox("rustskybox", "rusted_west.jpg", "rusted_east.jpg", "rusted_up.jpg", "rusted_down.jpg", "rusted_south.jpg", "rusted_north.jpg"));

}


Skybox::~Skybox(){
	delete ro;
}

RenderObject* Skybox::getRenderObject(){
	return ro;
}

void Skybox::Render(){
	r.RenderSkybox(*ro);
}