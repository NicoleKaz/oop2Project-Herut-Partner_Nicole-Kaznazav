#pragma once

#include "Command.h"
//#include "LevelsMenu.h"

class Controller;

class ScoreTableButton : public Command
{
public:

	ScoreTableButton(Controller* game, sf::RenderWindow& window, GameManager* manager);

	void execute() override;

private:
	//LevelsMenu m_levels_menu;
	Controller* m_game;
	//sf::RenderWindow& m_window;
};