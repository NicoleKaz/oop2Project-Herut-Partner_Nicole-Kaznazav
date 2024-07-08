#pragma once

#include "Command.h"
//#include "Game.h"

//#include "LevelsMenu.h"

class Controller;

class HelpButton : public Command
{
public:

	HelpButton(Controller* game, sf::RenderWindow& window, GameManager* manager);

	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	//Controller* m_game;
	//sf::RenderWindow& m_window;
};

