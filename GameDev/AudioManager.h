#pragma once
#include "Singleton.h"
#include <string>
#include <map>
#include <SFML/Audio.hpp>


/*
* SFML cannot blend? Need research
*/
class AudioManager : public Singleton<AudioManager>
{
public:

	friend class Singleton<AudioManager>;

	sf::Sound* GetSound(const std::string filename);
	sf::Sound* AddSound(const std::string filename);

	sf::Music* GetMusic(const std::string filename);
	sf::Music* AddMusic(const std::string filename);

protected:

	AudioManager();
	~AudioManager();

private:

	std::map<std::string, sf::Music*> music;
	std::map<std::string, sf::Sound*> sounds;

};

