#pragma once
#include "Singleton.h"
#include "Shader.h"
#include <string>
#include <map>

/**
 * @class	ShaderManager
 *
 * @brief	Manager for shaders.
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class ShaderManager : public Singleton<ShaderManager>
{
public:
	
	// Friend can access protected Constructors
	friend class Singleton<ShaderManager>;

	/**
	 * @fn	Shader* ShaderManager::GetShader(const std::string shaderName);
	 *
	 * @brief	Gets a shader with given name for shader sequence
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	shaderName	Name of the shader.
	 *
	 * @return	null if it fails, else the shader.
	 */

	Shader* GetShader(const std::string shaderName);

	/**
	 * @fn	Shader* ShaderManager::AddShader(const std::string shaderName, const std::string vertex, const std::string fragment, const std::string geometry = "", const std::string tcs = "", const std::string tes = "");
	 *
	 * @brief	Adds a shader if it is not already in the system
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	shaderName	Name of the shader.
	 * @param	vertex	  	The vertex.
	 * @param	fragment  	The fragment.
	 * @param	geometry  	The geometry.
	 * @param	tcs		  	The tesselation control shader
	 * @param	tes		  	The tesselation eval shader.
	 *
	 * @return	new or retrieved shader
	 */

	Shader* AddShader(const std::string shaderName, const std::string vertex,
		const std::string fragment, const std::string geometry = "",
		const std::string tcs = "", const std::string tes = "");

protected:

	ShaderManager();
	~ShaderManager();

private:

	std::map<std::string, Shader*> shaders;
};

