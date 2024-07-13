#include "Musics.h"

Musics::Musics()
{
	m_menuSound.setBuffer(m_soundBuffers[Menu_Song]);
	m_menuSound.setLoop(true);
	loadMusic();
}

void Musics::loadMusic()
{
	m_soundBuffers[Red_Song].loadFromFile("Red_Song.wav");
	m_soundBuffers[Pink_Song].loadFromFile("Pink_Song.wav");
	m_soundBuffers[Blue_Song].loadFromFile("Blue_Song.wav");
	m_soundBuffers[Menu_Song].loadFromFile("Menu_Song.wav");
}

Musics& Musics::instance()
{
	static Musics Music;
	return Music;
}



void Musics::playMenuSound()
{
	m_menuSound.play();
}

void Musics::stopMusic()
{
	m_menuSound.stop();
}

void Musics::playSongLevel(const GameSounds sound)
{
	m_levelSound.setBuffer(m_soundBuffers[sound]);
	m_levelSound.setLoop(true);
	m_levelSound.play();
}









