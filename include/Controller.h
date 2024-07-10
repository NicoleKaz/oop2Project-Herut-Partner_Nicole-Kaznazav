#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <sstream>
#include <iomanip>
#include "SwitchPlayerButton.h"
#include "ScoreTableButton.h"
#include <ExitGame.h>
#include "Resources.h"
#include "HelpButton.h"
#include "PlayButton.h"
#include "ExitGame.h"
#include "Menu.h"
#include "GameManager.h"



class Controller
{
public:
	Controller();
	void run();
	void handleSwitchPlayer(const sf::Vector2f location);
    void handleSwitchPlayerMouseMoved(const sf::Vector2f location);

	Menu& getMenu() { return m_menu; }

	void helpGame();
	int getPlayer();
	void quitGame();
	void chooseLevel();
	void addScore(int score);



private:	
	//sf::Sprite& m_background;
	sf::RenderWindow m_window;
	Menu m_menu;
	GameManager m_gameManager;
	Resources m_resources;
	ScoreTable m_scoreTable;

	
	std::string scoreFile = "scores.txt";
	sf::View m_gameView;
	sf::Clock m_GameClock;

	void handleMenuMouseMoved(const sf::Vector2f);

	int m_player = 0; 

	//sf::Clock m_game_clock;
	////private functions
	//void setView();
	//void winLoop();
	//void createScoreBoard(sf::Sprite&, sf::Sprite&, sf::Text&, sf::Text&, int&,
	//	sf::Text&, sf::Text&, sf::RectangleShape&, sf::RectangleShape&) const;

};