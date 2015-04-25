#include "Skybox.h"


Skybox::Skybox(){
	//ResourceManager::Instance().AddTexture("cubemap2.png");
	GLint cubemap = SOIL_load_OGL_cubemap(
		"assets/Textures/Skybox/rusted_west.jpg",
		"assets/Textures/Skybox/rusted_east.jpg",
		"assets/Textures/Skybox/rusted_up.jpg",
		"assets/Textures/Skybox/rusted_down.jpg",
		"assets/Textures/Skybox/rusted_south.jpg",
		"assets/Textures/Skybox/rusted_north.jpg",
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

	this->ro = new RenderObject(ResourceManager::Instance().AddMeshFromMethod("quad", 2),
		ResourceManager::Instance().AddShader("skybox", "SkyboxVert.glsl", "SkyboxFrag.glsl"),
		cubemap);

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