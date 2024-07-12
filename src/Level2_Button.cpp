#pragma once

#include "Level2_Button.h"
#include "Controller.h"

Level2_Button::Level2_Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
	:Command(game, window, manager)
{
}

void Level2_Button::execute()
{
	m_manager->getBoard().createLevel(Map2, LevelPink);
	m_manager->startGame();
}
