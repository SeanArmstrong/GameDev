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
