#include "AudioManager.h"


AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

sf::Sound* AudioManager::GetSound(const std::string filename){
	std::map<std::string, sf::Sound*>::iterator i = sounds.find(filename);

	if (i != sounds.end()){
		return i->second;
	}

	return NULL;
}

sf::Sound* AudioManager::AddSound(const std::string filename){
	sf::Sound* sound = GetSound(filename);

	if (sound == NULL){
		const std::string PATH = "assets/Sounds/";
		sf::SoundBuffer s;
		if (!s.loadFromFile(filename))
		{
			//Bad things
		}
		sound->setBuffer(s);
		sounds.insert(make_pair(filename, sound));

	}
	return sound;
}

sf::Music* AudioManager::GetMusic(const std::string filename){
	std::map<std::string, sf::Music*>::iterator i = music.find(filename);

	if (i != music.end()){
		return i->second;
	}

	return NULL;
}

/*
* Error here

*/
sf::Music* AudioManager::AddMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);

	if (m == NULL){
		const std::string PATH = "assets/Sounds/";
		if (!m->openFromFile(filename))
		{
			//Bad things
		}
		//music->insert(std::pair<std::string, sf::Music*>(filename, music));

	}
	return m;
}