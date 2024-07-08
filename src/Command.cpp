#include "Command.h"
#include "Controller.h"
#include "GameManager.h"

Command::Command(Controller* game, sf::RenderWindow& window, GameManager* manager)
    : m_game(game), m_window(window), m_manager(manager)
{
}
