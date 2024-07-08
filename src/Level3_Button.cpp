#pragma once

#include "Level3_Button.h"
#include "Controller.h"

Level3_Button::Level3_Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
	:Command(game, window, manager)
{
}

void Level3_Button::execute()
{
	//m_game->getMenu().stopSong();
	m_manager->getBoard().createLevel(Map1/*, WithoutYou_Song*/);
	m_manager->startGame();
	//m_game->getMenu().playSong();
}
