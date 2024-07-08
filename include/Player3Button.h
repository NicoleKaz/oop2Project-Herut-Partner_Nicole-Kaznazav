#pragma once

#include "Command.h"

class Controller;


class Player3Button : public Command
{
public:
    Player3Button(Controller* game, sf::RenderWindow& window, GameManager* manager);
    void execute() override;
};
