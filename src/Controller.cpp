#include "Controller.h"
#include <thread>
#include <chrono>


//Responsible for managing the game menu
Controller::Controller()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash"),
    m_menu(m_window),
    m_gameManager(m_window, m_menu)
{
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

    m_window.setView(m_gameView);
	loadCustomCursor();
};



//This function runs the game menu
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
                m_GameClock.restart();
                //getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                //performing the button action accordingly
                m_menu.action(location);
                break;
            }
            //handleMenuMouseMoved
			case sf::Event::MouseMoved:
			{
				const auto location = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				handleMenuMouseMoved(location);
				break;
			}
            }
        }
        if (m_gameManager.isWin())
        {
            m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            m_window.setView(m_gameView);
            //taking name to scoreboard
            fillScoreTable(); 
        }

    }
}

//This function is responsible for filling the scoreboard
void Controller::fillScoreTable()
{
    // Initialize the state for entering a username
    m_isEnteringName = true;
    m_username.clear();
    // Set up the "High Scores" title text
    m_enterNameText.setFont(Resources::instance().getFont());
    m_enterNameText.setString("High Scores");
    m_enterNameText.setCharacterSize(48);
    m_enterNameText.setFillColor(sf::Color::White);
    m_enterNameText.setPosition(300, 100);
    // Set up the prompt text for entering the name
    m_promptText.setFont(Resources::instance().getFont());
    m_promptText.setString("Enter your name: ");
    m_promptText.setCharacterSize(24);
    m_promptText.setFillColor(sf::Color::White);
    m_promptText.setPosition(300, 200);
    // Set up the background rectangle
    m_backgroundRect.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_backgroundRect.setFillColor(sf::Color(100, 100, 100, 150));
    // Event loop for capturing name input
    while (m_isEnteringName)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            //Handle text input event
            if (event.type == sf::Event::TextEntered && m_isEnteringName)
            {
                //Function to process text input
                handleTextEntered(event);
            }
        }
        // Clear the window for redrawing
        m_window.clear();
        // Draw the background rectangle, title text, and prompt text
        m_window.draw(m_backgroundRect);
        m_window.draw(m_enterNameText);
        m_window.draw(m_promptText);
        // Draw the entered name text
        sf::Text nameText;
        nameText.setFont(Resources::instance().getFont());
        nameText.setString(m_username);
        nameText.setCharacterSize(24);
        nameText.setFillColor(sf::Color::White);
        nameText.setPosition(300, 250);
        m_window.draw(nameText);
        //Display the updated window
        m_window.display();
    }

}


//This function handels the Name input
void Controller::handleTextEntered(const sf::Event& event)
{
    //Only handle printable ASCII characters
    if (event.text.unicode < 128)
    {
        //Convert the entered Unicode character to a char
        char enteredChar = static_cast<char>(event.text.unicode);
        //Handle backspace key press
        if (enteredChar == '\b') 
        {
            if (!m_username.empty())
                m_username.pop_back();
        }
        //Handle Enter key press
        else if (enteredChar == '\r')
        {
            m_isEnteringName = false;
            int coins = m_gameManager.getCoins();
            int score = 500000 - ((m_GameClock.getElapsedTime().asSeconds() * 8) + (coins * 5));
            m_menu.updateScoreTable(m_username, score);
        }
        //Handle other printable characters
        else
        {
            //Append the entered character to the username
            m_username += enteredChar;
        }
    }
}

//This functions handels the choose player menu
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
            m_menu.ButtonRelease((MenuPlayer)player);
        }
        else
        {
            m_menu.ButtonPress((MenuPlayer)player);
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
			m_menu.ButtonRelease((Button)player);
		}
		else
		{
			m_menu.ButtonPress((Button)player);
		}
        
    }
}


void Controller::quitGame()
{
    m_window.close();
}

//This function loads the custom cursor
void Controller::loadCustomCursor()
{
    // Load the custom cursor image
    cursorImage.loadFromFile("cursor.png");
    // Create the cursor from the image
    m_cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0, 0 });
    // Set the cursor for the window
    m_window.setMouseCursor(m_cursor);
}