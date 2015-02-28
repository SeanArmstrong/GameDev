#include "ShaderManager.h"


ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
	for (map<string, Shader*>::iterator i = shaders.begin(); i != shaders.end(); ++i){
		delete i->second;
	}
}

Shader* ShaderManager::GetShader(const std::string shaderName){
	map<string, Shader*>::iterator i = shaders.find(shaderName);

	if (i != shaders.end()){
		return i->second;
	}

	return NULL;
}

Shader* ShaderManager::AddShader(const std::string shaderName, const std::string vertex,
	const std::string fragment, const std::string geometry,
	const std::string tcs, const std::string tes){

	Shader* shader = GetShader(shaderName);

	if (shader == NULL){
		const string PATH = "assets/Shaders/";

		// TODO: Allow for geo, tcs and tes
		Shader* shader = new Shader(PATH + vertex, PATH + fragment);
		shaders.insert(make_pair(shaderName, shader));
	}
	return shader;
}
