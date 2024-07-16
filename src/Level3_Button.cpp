#pragma once

#include "Level3_Button.h"
#include "Controller.h"

Level3_Button::Level3_Button(sf::RenderWindow& window, GameManager& manager, Controller& game)
    : Command(window), m_manager(manager), m_game(game)
{
}

void Level3_Button::execute()
{
    m_game.getMusics().stopMenuMusic();
    m_manager.getMusics().playSongLevel(Blue_Song);
    m_manager.getBoard().createLevel(MapBlue, LevelBlue/*, WithoutYou_Song*/);
    m_manager.startGame();
    m_manager.getMusics().stopSongLevel(Blue_Song);
    m_game.getMusics().playMenuSound();
}