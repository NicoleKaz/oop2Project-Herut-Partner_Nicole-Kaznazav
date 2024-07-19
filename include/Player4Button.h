#pragma once
#include "Controller.h"
#include "Command.h"


class Controller;

class Player4Button : public Command
{
public:
    Player4Button(sf::RenderWindow& window, Controller& game, GameManager& manager);
    void execute() override;

private:
    GameManager& m_manager;
    Controller& m_game;
};
