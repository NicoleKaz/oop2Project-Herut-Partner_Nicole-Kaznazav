#pragma once
#include "Command.h"
#include "Musics.h"


class MuteMusic : public Command
{
public:
    MuteMusic(sf::RenderWindow&, Musics&);
    virtual void execute() override;

private:
    Musics& m_music;
};
