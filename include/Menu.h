#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ScoreTable.h"
#include "Resources.h"
#include "Command.h"


class Menu
{
public:
	Menu(sf::RenderWindow& window);
	void drawScoreTable() ;
	void updateScoreTable(const std::string& username, const int score);
	void updateScoreTable(const int score);
	void ButtonPress(const MenuPlayer player);
	void ButtonRelease(const MenuPlayer player);
	void playSound(Sound sound);
	void add(const Button button, std::unique_ptr<Command> command);
	void drawMenu()const;
	void displayRules()const;
	void action(const sf::Vector2f& location) const;
	void choosePlayer(const MenuPlayer player);
	const sf::Sprite getPlayer(const MenuPlayer player) const { return m_players[player]; }
	std::vector<GameTextures> getPlayerTextures() const;
	sf::Sprite getButton(const Button button) const { return m_buttons[0]; }

private:
	std::string scoreFile = "scores.txt";
	ScoreTable m_score_table;
	sf::RenderWindow& m_window;
	//arrays
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];
	sf::Sprite m_players[MENU_PLAYER];
	sf::Sprite m_background;
	sf::Sprite m_title;
	MenuPlayer m_player;
	void setPosition();
	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;

};
