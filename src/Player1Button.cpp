#include "Player1Button.h"
#include "Controller.h"

Player1Button::Player1Button(Controller* game, sf::RenderWindow& window,GameManager* manager)
    : Command(game, window, manager)
{
}

void Player1Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER1);
    m_manager->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}

