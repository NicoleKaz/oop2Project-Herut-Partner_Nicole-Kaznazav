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
    void togglePause();
    Board& getBoard() { return m_board; }
    Musics& getMusics() { return m_musics; }

private:
    void handlePauseMenu();
    Menu& m_menu;
    Musics m_musics;
    sf::RenderWindow& m_window;
    Board m_board;
    bool m_isFinish = false;
    bool m_isWin = false;
    bool m_isPaused = false;
    sf::View m_gameView;
    sf::View m_pauseView;

    int m_coins;
};
