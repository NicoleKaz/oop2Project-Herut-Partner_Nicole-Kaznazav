#pragma once
#include <SFML/Graphics.hpp>
#include "PlayersMenu.h"
#include "Command.h"


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
