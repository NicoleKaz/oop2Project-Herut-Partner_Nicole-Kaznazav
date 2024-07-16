#pragma once

#include "Level2_Button.h"
#include "Controller.h"

Level2_Button::Level2_Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
	:Command(game, window, manager)
{
}

void Level2_Button::execute()
{
    m_game->getMusics().stopMenuMusic();
    m_manager->getMusics().playSongLevel(Pink_Song);
    m_manager->getBoard().createLevel(MapRed, LevelRed);
    m_manager->startGame();
    m_manager->getMusics().stopSongLevel(Pink_Song);
    m_game->getMusics().playMenuSound();
}
