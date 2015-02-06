#pragma once
#include <string>
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Singleton.h"

class ResourceManager : public Singleton<ResourceManager>
{
public:

	// Friend can access protected Constructors
	friend class Singleton<ResourceManager>;

	/*
	* TEXTURE METHODS
	*/
	inline unsigned int GetTexture(std::string textureName){ 
		return TextureManager::Instance().GetTexture(textureName);
	}

	inline unsigned int AddTexture(const std::string filename){ 
		return TextureManager::Instance().AddTexture(filename); 
	}


	/*
	* Shader METHODS
	*/
	Shader* GetShader(const std::string shaderName){ 
		return ShaderManager::Instance().GetShader(shaderName);
	}

	Shader* AddShader(const std::string shaderName, const std::string vertex,
		const std::string fragment, const std::string geometry = "",
		const std::string tcs = "", const std::string tes = ""){
		return ShaderManager::Instance().AddShader(shaderName, vertex, fragment, geometry, tcs, tes);
	}

protected:

	ResourceManager(){
		Singleton<TextureManager>::Instance();
		Singleton<ShaderManager>::Instance();
	}

	~ResourceManager(){
		Singleton<TextureManager>::ResetInstance();
		Singleton<ShaderManager>::ResetInstance();
	}

private:
};

