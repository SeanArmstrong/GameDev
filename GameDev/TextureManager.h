#pragma once
#include "Singleton.h"
#include "SOIL.h"
#include <string>
#include <map>

class TextureManager : public Singleton<TextureManager>
{
public:

	// Friend can access protected Constructors
	friend class Singleton<TextureManager>;

	unsigned int GetTexture(const std::string filename);
	unsigned int AddTexture(const std::string filename);

protected:

	TextureManager();
	~TextureManager();

private:

	std::map<std::string, unsigned int> textures;
};

