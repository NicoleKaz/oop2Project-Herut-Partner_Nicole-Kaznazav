#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class Controller;
class GameManager;

class Command
{
public:
    Command(sf::RenderWindow& window);
    virtual ~Command() = default;
    virtual void execute() = 0;

protected:
    sf::RenderWindow& m_window;
};
