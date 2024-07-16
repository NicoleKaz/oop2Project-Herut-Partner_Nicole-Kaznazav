#pragma once

#include "PlayButton.h"
#include "Controller.h"
#include <Level1_Button.h>
#include <Level2_Button.h>
#include <Level3_Button.h>


PlayButton::PlayButton(sf::RenderWindow& window, GameManager& manager, Controller& game)
    :Command(window), m_manager(manager), m_game(game), m_levelsMenu(m_window, m_manager)
{
    //adding buttons to the submenu
    m_levelsMenu.add(level1, std::make_unique<Level1_Button>(m_window, m_manager, m_game));
    m_levelsMenu.add(level2, std::make_unique<Level2_Button>(m_window, m_manager, m_game));
    m_levelsMenu.add(level3, std::make_unique<Level3_Button>(m_window, m_manager, m_game));
}

void PlayButton::execute()
{
    bool click = false;
    while (m_window.isOpen() && !click)
    {
        m_window.clear();
        m_levelsMenu.drawLevelsMenu();  // Draw the player menu
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                //getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

                //performing the button action acordingly
                m_levelsMenu.action(location);
                click = true;
                break;
            }
            case sf::Event::MouseMoved:
            {
                //indicate if the mouse on the buttons 
                const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                m_levelsMenu.handleMouseMoved(location);
                break;
            }
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            break;
        }
    }
}




