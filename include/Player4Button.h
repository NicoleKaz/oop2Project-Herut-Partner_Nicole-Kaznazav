#pragma once

#include "Command.h"

class Controller;


class Player4Button : public Command
{
public:
    Player4Button(Controller* game, sf::RenderWindow& window, GameManager* manager);
    void execute() override;
};
