#include "Player2Button.h"


Player2Button::Player2Button(sf::RenderWindow& window, Controller& game, GameManager& manager)
    : Command(window), m_game(game), m_manager(manager)
{
}

void Player2Button::execute()
{
    // Execute the player switch logic for Player 2
    m_game.getMenu().choosePlayer(PLAYER2);
    m_manager.getBoard().switchPlayer(m_game.getMenu().getPlayerTextures());
}


