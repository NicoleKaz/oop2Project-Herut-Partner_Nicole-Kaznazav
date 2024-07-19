#pragma once
#include <LevelsMenu.h>
#include "Command.h"


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