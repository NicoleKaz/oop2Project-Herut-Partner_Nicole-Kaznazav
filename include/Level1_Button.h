#pragma once
#include "GameManager.h"
#include "Controller.h"
#include "Command.h"


class Controller;

class Level1_Button : public Command
{
public:
	Level1_Button(sf::RenderWindow&, GameManager&, Controller&);
	virtual void execute() override;

private:
	GameManager& m_manager;
	Controller& m_game; 
};
