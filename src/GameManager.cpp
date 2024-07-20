#include "GameManager.h"


GameManager::GameManager(sf::RenderWindow& window, Menu& menu)
    : m_window(window), m_menu(menu), m_board(m_window, m_menu.getPlayerTextures())
{
    m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
    m_pauseView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_pauseView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    m_coins = 0;
}

//This function runs the game 
void GameManager::startGame()
{
    m_isFinish = false;
    m_isPaused = false;
    //As long as the user did not exit the game, this loop ran
    while (m_window.isOpen() && !m_isFinish)
    {
        if (!m_isPaused)
        {
            //The game window is cleared
            m_window.clear(sf::Color::Color(0, 102, 102));
            m_window.setView(m_gameView);
            //Drawing the game board
            m_board.drawBoard();
            m_window.display();

            for (auto event = sf::Event{}; m_window.pollEvent(event); )
            {
                if (m_board.handleInput(event))
                {
                    m_isPaused = true;
                }
                break;
            }
            m_board.updateMovingDirections();
            m_board.moveObjects();
            m_board.handleCollision(); //maybe change the name 
            setView(); // update the game view and background 

            if (m_board.isWin())
            {
                m_isFinish = true;
                m_isWin = true;
            }
        }
        else
        {
            handlePauseMenu();
        }

        if (m_isFinish)
        {
            m_coins = m_board.getCoins();
            //reset board for next game
            m_board.resetBoard();
            //reset game view - (if the player exit with escape)
            m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            m_window.setView(m_gameView);
        }
    }
}

void GameManager::handlePauseMenu()
{
    m_window.setView(m_pauseView);
    sf::RectangleShape darkOverlay(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    darkOverlay.setFillColor(sf::Color(50, 50, 90, 8));
    m_window.draw(darkOverlay);
    m_menu.displayPauseMenu();
    m_window.display();

    // handle the pause menu
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
            m_isFinish = true;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            if (m_menu.getPause(RESUME).getGlobalBounds().contains(location))
            {
                m_isPaused = false;
                break;
            }
            else if (m_menu.getPause(MAIN_MENU).getGlobalBounds().contains(location))
            {
                m_isFinish = true;
                break;
            }
            else if (m_menu.getPause(MUTE).getGlobalBounds().contains(location))
            {
                m_musics.muteLevelMusic();
                break;
            }
        }

    }
}


void GameManager::setView()
{
    // keeping the last positions
    const float last_pos = m_gameView.getCenter().x;
    const b2Vec2 playerPosition = m_board.getPlayerPosition();
    const float playerX = playerPosition.x * SCALE;
    m_gameView.setCenter(playerX, WINDOW_HEIGHT / 2);
    m_board.viewBackground(playerX - last_pos); //make the background move with the view
}

//This function checks if the player has finished the game
bool GameManager::isWin()
{
    if (m_isWin)
    {
        m_isWin = false;
        return true;
    }
    return false;
}

//This function returns the points the player has collected in the game
int GameManager::getCoins() const
{
    return m_coins;
}

void GameManager::togglePause()
{
    m_isPaused = !m_isPaused;
}

