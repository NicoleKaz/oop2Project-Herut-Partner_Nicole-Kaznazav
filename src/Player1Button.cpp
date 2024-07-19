#include "Player1Button.h"


Player1Button::Player1Button(sf::RenderWindow& window, Controller& game, GameManager& manager)
    : Command(window), m_game(game), m_manager(manager)
{
}

void Player1Button::execute()
{
    // Execute the player switch logic for Player 1
    m_game.getMenu().choosePlayer(PLAYER1);
    m_manager.getBoard().switchPlayer(m_game.getMenu().getPlayerTextures());
}

