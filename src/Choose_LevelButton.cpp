//#pragma once
//
//#include "Choose_LevelButton.h"
//#include "Controller.h"
//#include "Level1_Button.h"
//#include "Level2_Button.h"
//#include "Level3_Button.h"
////#include "GreyhoundButton.h"
////#include "OnlyTheHorsesButton.h"
////#include "SpectreButton.h"
//
//
//Choose_LevelButton::Choose_LevelButton(Controller* game, sf::RenderWindow& window)
//	:Command(game, window), m_levelsMenu(m_game, m_window)
//{
//    m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
//    m_background.scale(1.6f, 1.6f);
//
//    for (int level = level1  ; level <= level3; level++)
//    {
//        m_menuLevel[level].setTexture(Resources::instance().getLevelsMenu((MenuLevels)level));
//
//    }
//    locateObjects();
//}
//
//
//void Choose_LevelButton::execute()
//{
//    while (m_window.isOpen())
//    {
//        m_window.clear();
//        m_levelsMenu.drawLevelsMenu();  // Draw the player menu
//        m_window.display();
//
//        if (auto event = sf::Event{}; m_window.waitEvent(event))
//        {
//            switch (event.type)
//            {
//            case sf::Event::MouseButtonReleased:
//            {
//                // Getting the click location, checking what button pressed
//                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
//
//                // Performing the button action accordingly
//                m_levelsMenu.handleAction(location);
//                return;
//            }
//            case sf::Event::MouseMoved:
//            {
//                // Indicate if the mouse is on the buttons
//                const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
//                m_levelsMenu.handleMouseMoved(location);
//                break;
//            }
//            case sf::Event::Closed:
//                m_window.close();
//                return;
//            }
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            return;
//        }
//    }
//}
//
