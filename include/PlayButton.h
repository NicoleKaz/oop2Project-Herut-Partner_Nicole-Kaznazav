#pragma once

#include "Command.h"
#include <LevelsMenu.h>

class Controller;

class PlayButton : public Command
{
public:
	PlayButton(sf::RenderWindow& , GameManager& , Controller&);
	void execute() override;

private:
	LevelsMenu m_levelsMenu;
	GameManager& m_manager;
	Controller& m_game;

};