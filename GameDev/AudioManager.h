#pragma once
#include "Singleton.h"
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>

/**
 * @class	AudioManager
 *
 * @brief	Manager for audio in the system
 * 			Deals with Music and Sounds
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */
class AudioManager : public Singleton<AudioManager>
{
public:

	friend class Singleton<AudioManager>;

	/**
	 * @fn	sf::Sound* AudioManager::GetSound(const std::string filename);
	 *
	 * @brief	Gets a sound by given filename
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	null if it fails, else the sound.
	 */
	sf::Sound* GetSound(const std::string filename);

	/**
	 * @fn	sf::Sound* AudioManager::AddSound(const std::string filename);
	 *
	 * @brief	Adds a sound if it does not already exist
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	null if it fails, else a sf::Sound*.
	 */
	sf::Sound* AddSound(const std::string filename);

	/**
	 * @fn	sf::Music* AudioManager::GetMusic(const std::string filename);
	 *
	 * @brief	Gets music track from filename
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	null if it fails, else the music.
	 */
	sf::Music* GetMusic(const std::string filename);

	/**
	 * @fn	sf::Music* AudioManager::AddMusic(const std::string filename);
	 *
	 * @brief	Adds music track if it doesn't exist
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 *
	 * @return	null if it fails, else a sf::Music*.
	 */
	sf::Music* AddMusic(const std::string filename);

	/**
	 * @fn	void AudioManager::AudioPlaySound(const std::string filename);
	 *
	 * @brief	Plays a sound
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	filename	Filename of the file.
	 */
	void AudioPlaySound(const std::string filename);

	/**
	* @fn	void AudioPlayMusic(const std::string filename);
	*
	* @brief	Plays Music once
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	filename	Filename of the file.
	*/
	void AudioPlayMusic(const std::string filename);

	/**
	* @fn	void AudioPauseMusic(const std::string filename);
	*
	* @brief	Pauses music of filename if playing
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	filename	Filename of the file.
	*/
	void AudioPauseMusic(const std::string filename);

	/**
	* @fn	void AudioPlayAndLoopMusic(const std::string filename);
	*
	* @brief	Plays and loops music
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	filename	Filename of the file.
	*/
	void AudioPlayAndLoopMusic(const std::string filename);

	/**
	* @fn	void AudioPlayAndLoopMusic(const std::string filename);
	*
	* @brief	Stops music playing
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	filename	Filename of the file.
	*/
	void AudioStopMusic(const std::string filename);

	/**
	* @fn	void AudioPlayAndLoopMusic(const std::string filename);
	*
	* @brief	Returns if filename track is playing
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param	filename	Filename of the file.
	*/
	bool AudioIsMusicPlaying(const std::string filename);

protected:

	AudioManager();
	~AudioManager();

private:

	std::map<std::string, sf::Music*> music;
	std::map<std::string, sf::Sound*> sounds;
	std::vector<sf::SoundBuffer*> buffs;

	//Store the current playing track for volume control
	//sf::Music* currentTrack;

};

