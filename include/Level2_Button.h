#pragma once

#include "Command.h"

class Controller;

class Level2_Button : public Command
{
public:
	Level2_Button(sf::RenderWindow&, GameManager&, Controller&);
	virtual void execute() override;

private:
	GameManager& m_manager;
	Controller& m_game;

};
