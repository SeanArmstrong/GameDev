#include "TextureManager.h"

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

unsigned int TextureManager::GetTexture(const std::string textureName){
	std::map<std::string, unsigned int>::iterator i = textures.find(textureName);

	if (i != textures.end()){
		return i->second;
	}

	return NULL;
}

unsigned int TextureManager::AddTexture(const std::string textureName){

	unsigned int texture = GetTexture(textureName);

	if (texture == NULL){
		const std::string PATH = "assets/Textures/";
		texture = SOIL_load_OGL_texture((PATH + textureName).c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
		textures.insert(make_pair(textureName, texture));
	}
	return texture;
}
