#include "TextureManager.h"

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager(){
	std::map<std::string, GLuint>::iterator it;
	for (it = textures.begin(); it != textures.end(); ++it) {
		glDeleteTextures(1, &it->second);
	}
}

unsigned int TextureManager::GetTexture(const std::string fileName){
	std::map<std::string, GLuint>::iterator i = textures.find(fileName);

	if (i != textures.end()){
		return i->second;
	}

	return NULL;
}

unsigned int TextureManager::AddTexture(const std::string fileName){

	unsigned int texture = GetTexture(fileName);

	if (texture == NULL){
		const std::string PATH = "assets/Textures/";
		texture = SOIL_load_OGL_texture((PATH + fileName).c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
		textures.insert(make_pair(fileName, texture));
	}
	return texture;
}

unsigned int TextureManager::AddSkybox(const std::string name, const std::string west, const std::string east,
	const std::string up, const std::string down, const std::string south, const std::string north){

	unsigned int texture = GetTexture(name);

	if (texture == NULL){
		const std::string PATH = "assets/Textures/Skybox/";
		texture = SOIL_load_OGL_cubemap(
			(PATH + west).c_str(),
			(PATH + east).c_str(),
			(PATH + up).c_str(),
			(PATH + down).c_str(),
			(PATH + south).c_str(),
			(PATH + north).c_str(),
			SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);;

		textures.insert(make_pair(name, texture));
	}
	return texture;
}
