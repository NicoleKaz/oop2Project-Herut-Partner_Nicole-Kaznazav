#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow& window, Menu& menu)
    : m_window(window), m_menu(menu), m_board(m_window, m_menu.getPlayerTextures())
{
   	m_gameView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_gameView.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
    m_coins = 0;
}

void GameManager::startGame()
{
    m_isFinish = false;
    //As long as the user did not exit the game, this loop ran
    while (m_window.isOpen() && !m_isFinish)
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
                m_isFinish = true;
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

void GameManager::setView()
{
    // keeping the last positions
    const float last_pos = m_gameView.getCenter().x;
    const b2Vec2 playerPosition = m_board.getPlayerPosition();
    const float playerX = playerPosition.x * SCALE;
    m_gameView.setCenter(playerX, WINDOW_HEIGHT / 2);
    m_board.viewBackground(playerX - last_pos); //make the background move with the view
}

bool GameManager::isWin() 
{
    if (m_isWin)
    {
        m_isWin = false;
        return true;
    }
    return false;
}


int GameManager::getCoins() const
{
	return m_coins;
}

Board& GameManager::getBoard()
{
    return m_board;
}
