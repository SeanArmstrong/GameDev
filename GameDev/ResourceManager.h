#pragma once
#include <string>
#include "ShaderManager.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "MeshManager.h"
#include "Singleton.h"

class ResourceManager : public Singleton<ResourceManager>
{
public:

	enum MeshGenerationMethods{
		GENERATE_TRIANGLE = 1,
		GENERATE_QUAD = 2,
		GENERATE_LINE = 3
	};

	// Friend can access protected Constructors
	friend class Singleton<ResourceManager>;

	/*
	* TEXTURE METHODS
	*/
	inline unsigned int GetTexture(std::string fileName){
		return TextureManager::Instance().GetTexture(fileName);
	}

	inline unsigned int AddTexture(const std::string filename){ 
		return TextureManager::Instance().AddTexture(filename); 
	}

	/*
	* Mesh METHODS
	*/
	Mesh* GetMesh(const std::string meshName) { return MeshManager::Instance().GetMesh(meshName); }
	Mesh* AddMeshFile(const std::string meshName, const int type, const std::string fileName = ""){
		return MeshManager::Instance().AddMeshFile(meshName, type, fileName);
	}
	Mesh* AddMeshFromMethod(const std::string meshName, int method){
		return MeshManager::Instance().AddMeshFromMethod(meshName, method);
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

	/*
	* Audio Methods
	*/
	sf::Sound* GetSound(const std::string filename){
		return AudioManager::Instance().GetSound(filename);
	}
	sf::Sound* AddSound(const std::string filename){
		return AudioManager::Instance().AddSound(filename);
	}

	sf::Music* GetMusic(const std::string filename){
		return AudioManager::Instance().GetMusic(filename);
	}
	sf::Music* AddMusic(const std::string filename){
		return AudioManager::Instance().AddMusic(filename);
	}

protected:

	ResourceManager(){
		Singleton<TextureManager>::Instance();
		Singleton<ShaderManager>::Instance();
		Singleton<AudioManager>::Instance();
	}

	virtual ~ResourceManager(){
		Singleton<TextureManager>::ResetInstance();
		Singleton<ShaderManager>::ResetInstance();
		Singleton<AudioManager>::ResetInstance();
	}

private:
};

