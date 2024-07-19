#include "Level2_Button.h"


Level2_Button::Level2_Button(sf::RenderWindow& window, GameManager& manager, Controller& game)
    : Command(window), m_manager(manager), m_game(game)
{
}

void Level2_Button::execute()
{
    m_game.getMusics().stopMenuMusic();
    m_manager.getMusics().playSongLevel(Pink_Song);
    m_manager.getBoard().createLevel(MapPink, LevelPink);
    m_manager.startGame();
    m_manager.getMusics().stopSongLevel(Pink_Song);
    m_game.getMusics().playMenuSound();
}
