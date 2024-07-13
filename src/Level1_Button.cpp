#include "Level1_Button.h"

Level1_Button::Level1_Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
    : Command(game, window, manager)
{
}

void Level1_Button::execute()
{
	m_game->getMusics().stopMusic();
    m_manager->getMusics().playSongLevel(Red_Song);
    m_manager->getBoard().createLevel(Map1, LevelRed);
    m_manager->startGame();
}