#include "HelpButton.h"
#include "Controller.h"


HelpButton::HelpButton(sf::RenderWindow& window, Controller& game)
    : Command(window), m_game(game)
{
}

//display the Help window 
void HelpButton::execute()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_game.getMenu().displayRules();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                return;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }
    }
}
