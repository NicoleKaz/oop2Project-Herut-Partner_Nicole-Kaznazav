#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h" 
#include "Menu.h"


class GameManager
{
public:
    GameManager(sf::RenderWindow& window, Menu& menu);

    void startGame();
    void setView();
    Board& getBoard();


private:
    Menu& m_menu;
    sf::RenderWindow& m_window;
    Board m_board;
    bool m_isFinish = false;
    sf::View m_gameView;

};
