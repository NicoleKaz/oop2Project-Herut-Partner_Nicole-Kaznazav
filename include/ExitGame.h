#pragma once
#include "Command.h"


class Controller;

class ExitGame : public Command
{
public:
	ExitGame(sf::RenderWindow& window, Controller& game);
	void execute() override;

private:
	Controller& m_game;

};