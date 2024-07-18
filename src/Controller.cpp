#include "Controller.h"
#include <thread>
#include <chrono>
#include <iostream>

Controller::Controller()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_gameManager(m_window, m_menu)
{
    //m_menuSound.setBuffer(Resources::instance().getSoundBuffer(Menu_Song));
    //m_menuSound.setLoop(true);
    m_window.setFramerateLimit(120);
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    //adding menu buttons:
    m_menu.add(PLAY, std::make_unique<PlayButton>(m_window, m_gameManager, *this));
    m_menu.add(HELP, std::make_unique<HelpButton>(m_window, *this));
    m_menu.add(SWITCH_PLAYER, std::make_unique<SwitchPlayerButton>(m_window, m_gameManager, *this));
    m_menu.add(SCORE_TABLE, std::make_unique<ScoreTableButton>(m_window, *this));
    m_menu.add(EXIT, std::make_unique<ExitGame>(m_window, *this));
    m_menu.add(MUTE_MUSIC, std::make_unique<MuteMusic>(m_window, m_musics));


    // הגדרות התצוגה
    m_window.setView(m_gameView);
};

void Controller::run()
{
    m_musics.playMenuSound();
    m_GameClock.restart();
    while (m_window.isOpen())
    {
        //display the first window 
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_menu.drawMenu();
        m_window.display();

        sf::Event event;
        if (m_window.waitEvent(event))
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
        //m_musics.playMenuSound();
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
    m_isEnteringName = true;
    m_username.clear();

    // עיצוב הכותרת והטקסט
    m_enterNameText.setFont(Resources::instance().getFont());
    m_enterNameText.setString("High Scores");
    m_enterNameText.setCharacterSize(48);
    m_enterNameText.setFillColor(sf::Color::White);
    m_enterNameText.setPosition(300, 100);

    m_promptText.setFont(Resources::instance().getFont());
    m_promptText.setString("Enter your name: ");
    m_promptText.setCharacterSize(24);
    m_promptText.setFillColor(sf::Color::White);
    m_promptText.setPosition(300, 200);

    // עיצוב הרקע
    m_backgroundRect.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_backgroundRect.setFillColor(sf::Color(100, 100, 100, 150)); // רקע שחור שקוף

    while (m_isEnteringName)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (event.type == sf::Event::TextEntered && m_isEnteringName)
            {
                handleTextEntered(event);
            }
        }

        m_window.clear();

        // ציור הרקע, הכותרת והטקסט
        m_window.draw(m_backgroundRect);
        m_window.draw(m_enterNameText);
        m_window.draw(m_promptText);

        sf::Text nameText;
        nameText.setFont(Resources::instance().getFont());
        nameText.setString(m_username);
        nameText.setCharacterSize(24);
        nameText.setFillColor(sf::Color::White);
        nameText.setPosition(300, 250);
        m_window.draw(nameText);

        m_window.display();
    }
}

void Controller::handleTextEntered(const sf::Event& event)
{
    if (event.text.unicode < 128)
    {
        char enteredChar = static_cast<char>(event.text.unicode);
        if (enteredChar == '\b') // טיפול במחיקת תו
        {
            if (!m_username.empty())
                m_username.pop_back();
        }
        else if (enteredChar == '\r') // טיפול בלחיצת Enter
        {
            m_isEnteringName = false;
            int score = m_gameManager.getCoins();
            m_menu.updateScoreTable(m_username, score);
        }
        else
        {
            m_username += enteredChar;
        }
    }
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
    for (int player = PLAY; player <= MUTE_MUSIC; player++)
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
