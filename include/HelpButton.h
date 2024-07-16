#pragma once

#include "Command.h"
//#include "Game.h"

//#include "LevelsMenu.h"

class Controller;

class HelpButton : public Command
{
public:
	HelpButton(sf::RenderWindow& window, Controller& game);
	void execute() override;

private:
	Controller& m_game;

};

