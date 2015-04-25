#pragma once
#include "Singleton.h"
#include "SOIL.h"
#include <string>
#include <map>
#include <GL/glew.h>

/**
 * @class	TextureManager
 *
 * @brief	Manager for textures.
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class TextureManager : public Singleton<TextureManager>
{
public:

	// Friend can access protected Constructors
	friend class Singleton<TextureManager>;

	/**
	 * @fn	unsigned int TextureManager::GetTexture(const std::string filename);
	 *
	 * @brief	Gets a texture by given name
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	The texture.
	 */

	unsigned int GetTexture(const std::string filename);

	/**
	 * @fn	unsigned int TextureManager::AddTexture(const std::string filename);
	 *
	 * @brief	Adds a texture if it is not already loaded
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	An textures GLuint
	 */

	unsigned int AddTexture(const std::string filename);
	unsigned int AddSkybox(const std::string name, const std::string west, const std::string east,
		const std::string up, const std::string down, const std::string south, const std::string north);

protected:

	TextureManager();
	~TextureManager();

private:

	std::map<std::string, GLuint> textures;
};

