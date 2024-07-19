#include "Musics.h"

Musics::Musics()
{
	m_menuSound.setBuffer(m_soundBuffers[Menu_Song]);
	m_menuSound.setLoop(true);
	loadMusic();
}

void Musics::loadMusic()
{
	m_soundBuffers[Red_Song].loadFromFile("Red_Song.ogg");
	m_soundBuffers[Pink_Song].loadFromFile("Pink_Song.ogg");
	m_soundBuffers[Blue_Song].loadFromFile("Blue_Song.ogg");
	m_soundBuffers[Menu_Song].loadFromFile("Menu_Song.ogg");
}

//implementation of the Singleton design pattern 
//ensures that a class has only one instance and provides a global point of access to it.
Musics& Musics::instance()
{
	static Musics Music;
	return Music;
}

void Musics::muteMusic(sf::Sound& sound)
{
	if (sound.getStatus() == sf::Sound::Playing)
	{
		sound.pause();
	}
	else {
		sound.play();
	}
}

void Musics::muteMenuMusic()
{
	muteMusic(m_menuSound);
}

void Musics::muteLevelMusic()
{
	muteMusic(m_levelSound);
}

void Musics::playMenuSound()
{
	m_menuSound.play();
}

void Musics::stopMenuMusic()
{
	m_menuSound.stop();
}

void Musics::playSongLevel(const GameSounds sound)
{
	m_levelSound.setBuffer(m_soundBuffers[sound]);
	m_levelSound.setLoop(true);
	m_levelSound.play();
}

void Musics::stopSongLevel(const GameSounds sound)
{
	m_levelSound.stop();
}









