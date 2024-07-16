#pragma once

#include "Command.h"

class Controller;


class Player4Button : public Command
{
public:
    Player4Button(sf::RenderWindow& window, Controller& game, GameManager& manager);
    void execute() override;

private:
    Controller& m_game;
    GameManager& m_manager;
};
