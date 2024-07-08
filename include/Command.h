#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class Controller;
class GameManager;

class Command
{
public:
    Command(Controller* game, sf::RenderWindow& window, GameManager* manager);
    virtual ~Command() = default;
    virtual void execute() = 0;

protected:
    Controller* m_game;
    sf::RenderWindow& m_window;
    GameManager* m_manager;  
};
