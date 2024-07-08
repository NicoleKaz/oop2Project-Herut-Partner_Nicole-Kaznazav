#include "Player4Button.h"
#include "Controller.h"

Player4Button::Player4Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
    : Command(game, window, manager)
{
}

void Player4Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER4);
    m_manager->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}


