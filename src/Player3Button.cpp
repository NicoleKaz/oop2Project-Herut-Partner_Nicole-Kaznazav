#include "Player3Button.h"
#include "Controller.h"

Player3Button::Player3Button(sf::RenderWindow& window, Controller& game, GameManager& manager)
    : Command(window), m_game(game), m_manager(manager)
{
}

void Player3Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game.getMenu().choosePlayer(PLAYER3);
    m_manager.getBoard().switchPlayer(m_game.getMenu().getPlayerTextures());
}


