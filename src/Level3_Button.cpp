#pragma once

#include "Level3_Button.h"
#include "Controller.h"

Level3_Button::Level3_Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
	:Command(game, window, manager)
{
}

void Level3_Button::execute()
{
    m_game->getMusics().stopMenuMusic();
    m_manager->getMusics().playSongLevel(Blue_Song);
    m_manager->getBoard().createLevel(MapRed, LevelRed);
    m_manager->startGame();
    m_manager->getMusics().stopSongLevel(Blue_Song);
    m_game->getMusics().playMenuSound();
}