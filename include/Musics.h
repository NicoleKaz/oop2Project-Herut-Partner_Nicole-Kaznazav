#pragma once
#include <SFML/Audio.hpp>
#include <Resources.h>


enum GameSounds { Menu_Song, Red_Song, Pink_Song, Blue_Song };
const int SOUNDS = 10;


class Musics
{
public:
	Musics();
	static Musics& instance();
	void muteMusic(sf::Sound& sound); // Function to mute/unmute any sf::Sound object
	void playMenuSound();
	void stopMenuMusic();
	void playSongLevel(const GameSounds sound);
	void stopSongLevel(const GameSounds sound);
	void muteMenuMusic();
	void muteLevelMusic();


	const sf::SoundBuffer& getSoundBuffer(const GameSounds sound) const { return m_soundBuffers[sound]; }

private:
	sf::Sound m_menuSound;
	sf::Sound m_levelSound;
	sf::SoundBuffer m_soundBuffers[SOUNDS];
	void loadMusic();
};