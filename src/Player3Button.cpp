#include "Player3Button.h"
#include "Controller.h"

Player3Button::Player3Button(Controller* game, sf::RenderWindow& window, GameManager* manager)
    : Command(game, window, manager)
{
}

void Player3Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game->getMenu().choosePlayer(PLAYER3);
    m_manager->getBoard().switchPlayer(m_game->getMenu().getPlayerTextures());
}


