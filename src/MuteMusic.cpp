#pragma once

#include "MuteMusic.h"
#include "Musics.h"


MuteMusic::MuteMusic(sf::RenderWindow& window, Musics& music)
    :Command(window), m_music(music)
{
}

void MuteMusic::execute()
{
	m_music.muteMusic();
}

