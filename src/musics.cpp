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

Musics& Musics::instance()
{
	static Musics Music;
	return Music;
}

void Musics::muteMusic()
{
	if (m_menuSound.getStatus() == sf::Sound::Playing)
	{
		m_menuSound.pause();
	}
	else
	{
		m_menuSound.play();
	}
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









