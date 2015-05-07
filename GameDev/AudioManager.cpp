#include "AudioManager.h"


AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
	for (std::map<std::string, sf::Music*>::iterator i = music.begin(); i != music.end(); ++i){
		delete i->second;
	}

	for (std::map<std::string, sf::Sound*>::iterator i = sounds.begin(); i != sounds.end(); ++i){
		delete i->second;
	}

	std::vector<sf::SoundBuffer*> buffs;
	for (std::vector<sf::SoundBuffer*>::iterator i = buffs.begin(); i != buffs.end(); ++i){
		delete (*i);
	}
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

sf::Music* AudioManager::AddMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);

	if (m == NULL){
		const std::string PATH = "assets/Sounds/";

		m = new sf::Music();

		if (!m->openFromFile(PATH + filename))
		{
			delete m;
			std::cout << "Failed to load Music File" << std::endl;
		}

		music.insert(make_pair(filename, m));

	}
	return m;
}

void AudioManager::AudioPlaySound(const std::string filename){
	sf::Sound* s = GetSound(filename);
	if (s){
		s->play();
	}
}
void AudioManager::AudioPlayMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);
	if (m){
		m->play();
	}
}

void AudioManager::AudioPauseMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);
	if (m){
		m->pause();
	}
}
void AudioManager::AudioPlayAndLoopMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);
	if (m){
		m->play();
		m->setLoop(true);
		std::cout << "Looping Music " << filename << std::endl;
	}
}

void AudioManager::AudioStopMusic(const std::string filename){
	sf::Music* m = GetMusic(filename);
	if (m){
		m->stop();
	}
}

bool AudioManager::AudioIsMusicPlaying(const std::string filename){
/*	sf::Music* m = GetMusic(filename);
	if (m){
		return (m->getStatus == sf::Music::Status::Playing);
	}
	*/
	return false;
}
