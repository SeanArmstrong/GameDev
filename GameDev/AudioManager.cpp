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

		sound = new sf::Sound();

		sf::SoundBuffer* s = new sf::SoundBuffer();

		if (!s->loadFromFile(PATH + filename))
		{
			delete sound;
			delete s;
			return NULL;
			//Bad things
		}
		buffs.push_back(s);
		sound->setBuffer(*s);
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

void AudioManager::AudioPlaySound(const std::string filename){
	sf::Sound* s = GetSound(filename);
	if (s){
		s->play();
	}
}