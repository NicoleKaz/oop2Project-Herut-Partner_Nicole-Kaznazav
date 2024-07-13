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
#include "Musics.h"



class Controller
{
public:
	Controller();
	void run();
	void fillScoreTable();
	void handleSwitchPlayer(const sf::Vector2f location);
    void handleSwitchPlayerMouseMoved(const sf::Vector2f location);

	Menu& getMenu() { return m_menu; }
	Musics& getMusics() { return m_musics; }


	void helpGame();
	int getPlayer();
	void quitGame();
	void chooseLevel();



private:	
	//sf::Sprite& m_background;
	sf::RenderWindow m_window;
	Menu m_menu;
	Musics m_musics;
	GameManager m_gameManager;
	Resources m_resources;

	
	//std::string scoreFile = "scores.txt";
	sf::View m_gameView;
	sf::Clock m_GameClock;

	void handleMenuMouseMoved(const sf::Vector2f);

	int m_player = 0; 

	void handleTextEntered(const sf::Event& event); // פונקציה יעודית לטיפול בקלט טקסט

	std::string m_username;
	bool m_isEnteringName = false;
	sf::Text m_enterNameText;
	sf::Text m_promptText;
	sf::RectangleShape m_backgroundRect;

	//sf::Clock m_game_clock;
	////private functions
	//void setView();
	//void winLoop();
	//void createScoreBoard(sf::Sprite&, sf::Sprite&, sf::Text&, sf::Text&, int&,
	//	sf::Text&, sf::Text&, sf::RectangleShape&, sf::RectangleShape&) const;

};