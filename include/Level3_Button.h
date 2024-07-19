#pragma once
#include "GameManager.h"
#include "Controller.h"
#include "Command.h"


class Controller;

class Level3_Button : public Command
{
public:
	Level3_Button(sf::RenderWindow&, GameManager&, Controller&);
	virtual void execute() override;

private:
	GameManager& m_manager;
	Controller& m_game;
};
