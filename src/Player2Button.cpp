#include "Player2Button.h"
#include "Controller.h"

Player2Button::Player2Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
    : Command(game, window, manager)
{
}

void Player2Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER2);
    m_manager->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}


