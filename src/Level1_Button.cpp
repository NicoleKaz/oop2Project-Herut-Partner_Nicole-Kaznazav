#include "Level1_Button.h"

Level1_Button::Level1_Button(sf::RenderWindow& window, GameManager& manager, Controller& game)
    : Command(window), m_manager(manager), m_game(game)
{
}

void Level1_Button::execute()
{
	m_game.getMusics().stopMenuMusic();
    m_manager.getMusics().playSongLevel(Red_Song);
    m_manager.getBoard().createLevel(MapRed, LevelRed);
    m_manager.startGame();
    m_manager.getMusics().stopSongLevel(Red_Song);
    m_game.getMusics().playMenuSound();

}