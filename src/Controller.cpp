#include "Controller.h"
#include <thread>
#include <chrono>
#include <iostream>

Controller::Controller()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_gameManager(m_window, m_menu)
{
    m_window.setFramerateLimit(120);
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    //adding menu buttons:
    m_menu.add(PLAY, std::make_unique<PlayButton>(this, m_window, &m_gameManager));
    m_menu.add(HELP, std::make_unique<HelpButton>(this, m_window, &m_gameManager));
    m_menu.add(SWITCH_PLAYER, std::make_unique<SwitchPlayerButton>(this, m_window, &m_gameManager));
    m_menu.add(SCORE_TABLE, std::make_unique<ScoreTableButton>(this, m_window, &m_gameManager));
    m_menu.add(EXIT, std::make_unique<ExitGame>(this, m_window, &m_gameManager));

    // הגדרות התצוגה
    m_window.setView(m_gameView);
};

void Controller::run()
{
    m_GameClock.restart();
    while (m_window.isOpen())
    {
        //display the first window 
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_menu.drawMenu();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                m_window.close();
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                //getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                // const int button = m_menu.getOptionFromUser(location);l

                //performing the button action accordingly
                m_menu.action(location);
                break;
            }
            //case sf::Event::MouseMoved:
            //{
            //    //indicate if the mouse on the buttons 
            //    const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            //    m_menu.handleMenuMouseMoved(location);
            //    break;
            //}

            }
        }

        if (m_gameManager.isWin())
        {
			//m_gameManager.setWin(false);
			//m_gameManager.setFinish(false);
           // m_menu.updateScoreTable(m_gameManager.getCoins());
            m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            m_window.setView(m_gameView);
            fillScoreTable(); //taking name to scoreboard
        }

    }
}

void Controller::fillScoreTable()
{
    std::string username;
    std::cout << "Enter your name: ";
    std::cin >> username; // קבלת שם המשתמש מהשחקן

    int score = m_gameManager.getCoins(); // קבלת הניקוד של השחקן
    m_menu.updateScoreTable(username, score); // עדכון טבלת השיאים עם השם והניקוד
}


void Controller::handleSwitchPlayer(const sf::Vector2f location)
{
    //loop to go over the buttons
    for (int player = PLAYER1; player <= PLAYER4; player++)
    {
        //check if a button pressed
        if ((m_menu.getPlayer((MenuPlayer)player).getGlobalBounds().contains(location)))
        {
            m_menu.choosePlayer((MenuPlayer)player);
            break;
        }
    }
}

void Controller::handleSwitchPlayerMouseMoved(const sf::Vector2f location)
{
    //loop to go over the buttons
    for (int player = PLAYER1; player <= PLAYER4; player++)
    {
        //check if a button pressed
        if ((m_menu.getPlayer((MenuPlayer)player).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((MenuPlayer)player);
        }
        else
        {
            m_menu.ButtonRelease((MenuPlayer)player);
        }
    }
}

//This function checks whether one of the buttons in menu has been pressed
void Controller::handleMenuMouseMoved(const sf::Vector2f location)
{
    //loop to go over the buttons
    for (int player = PLAY; player <= EXIT; player++)
    {
        //check if a button pressed
        if ((m_menu.getButton((Button)player).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((MenuPlayer)player);
        }
        else
        {
            m_menu.ButtonRelease((MenuPlayer)player);
        }
    }
}


void Controller::quitGame()
{
    m_window.close();
}

void Controller::chooseLevel()
{
}

