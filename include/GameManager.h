#pragma once
#include <SFML/Graphics.hpp>
#include "Musics.h"
#include "Board.h" 
#include "Menu.h"


class GameManager
{
public:
    GameManager(sf::RenderWindow& window, Menu& menu);
    void startGame();
    void setView();
    bool isWin();
    int getCoins() const;
    Board& getBoard() { return m_board; }
    Musics& getMusics() { return m_musics; }

private:
    Menu& m_menu;
    Musics m_musics;
    sf::RenderWindow& m_window;
    Board m_board;
    bool m_isFinish = false;
    bool m_isWin = false;
    sf::View m_gameView;
    int m_coins;
};
