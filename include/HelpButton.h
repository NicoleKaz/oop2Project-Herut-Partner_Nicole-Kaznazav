#pragma once
#include "Command.h"


class Controller;

class HelpButton : public Command
{
public:
	HelpButton(sf::RenderWindow& window, Controller& game);
	void execute() override;

private:
	Controller& m_game;
};

