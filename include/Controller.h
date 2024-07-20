#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <sstream>
#include <iomanip>
#include "SwitchPlayerButton.h"
#include "ScoreTableButton.h"
#include "GameManager.h"
#include "HelpButton.h"
#include "PlayButton.h"
#include "Resources.h"
#include "MuteMusic.h"
#include "ExitGame.h"
#include "Musics.h"
#include "Menu.h"


class Controller 
{
public:
    Controller();
    void run();
    void fillScoreTable();
    void handleSwitchPlayer(const sf::Vector2f location);
    void quitGame();
    Menu& getMenu() { return m_menu; }
    Musics& getMusics() { return m_musics; }

private:
    Menu m_menu;
    Musics m_musics;
    GameManager m_gameManager;
    std::string m_username;
    sf::View m_gameView;
    sf::Clock m_GameClock;
    sf::RenderWindow m_window;
    sf::Text m_enterNameText;
    sf::Text m_promptText;
    sf::RectangleShape m_backgroundRect;
	sf::RectangleShape m_nameRect;
    void handleMenuMouseMoved(const sf::Vector2f);
    void handleTextEntered(const sf::Event& event); 
    void loadCustomCursor();
    bool m_isEnteringName = false;
    sf::Cursor m_cursor;
    sf::Image cursorImage;
};
