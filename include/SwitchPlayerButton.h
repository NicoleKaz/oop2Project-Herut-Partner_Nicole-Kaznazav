#pragma once

#include "Command.h"
#include "PlayersMenu.h"
#include <SFML/Graphics.hpp>

class SwitchPlayerButton : public Command 
{
public:
    SwitchPlayerButton(Controller* game, sf::RenderWindow& window,GameManager* manager);
    virtual void execute()override;
    ;
private:
    PlayersMenu m_playerMenu;
};
