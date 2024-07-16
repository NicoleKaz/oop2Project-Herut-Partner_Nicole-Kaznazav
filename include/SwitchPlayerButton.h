#pragma once

#include "Command.h"
#include "PlayersMenu.h"
#include <SFML/Graphics.hpp>

class SwitchPlayerButton : public Command
{
public:
    SwitchPlayerButton(sf::RenderWindow& window, GameManager& manager, Controller& game);
    virtual void execute()override;

private:
    PlayersMenu m_playerMenu;
    GameManager& m_manager;
    Controller& m_game;
};
