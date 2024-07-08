#pragma once

#include "Command.h"
#include "Controller.h"
#include "GameManager.h"

class Controller;

class Level1_Button : public Command
{
public:
	Level1_Button(Controller*, sf::RenderWindow& ,GameManager*);
	virtual void execute() override;  

private:

};
