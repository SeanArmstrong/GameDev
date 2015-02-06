#pragma once
#include "Singleton.h"
#include "Shader.h"
#include <string>
#include <map>

class ShaderManager : public Singleton<ShaderManager>
{
public:
	
	// Friend can access protected Constructors
	friend class Singleton<ShaderManager>;

	Shader* GetShader(const std::string shaderName);
	Shader* AddShader(const std::string shaderName, const std::string vertex,
		const std::string fragment, const std::string geometry = "",
		const std::string tcs = "", const std::string tes = "");

protected:

	ShaderManager();
	~ShaderManager();

private:

	std::map<std::string, Shader*> shaders;
};

