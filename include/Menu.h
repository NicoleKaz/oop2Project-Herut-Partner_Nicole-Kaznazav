#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Command.h"
#include <vector>
#include <memory>





class Menu
{
public:

	Menu(sf::RenderWindow& window);
	sf::Sprite getButton(const Button) const;
	void ButtonPress(const MenuPlayer player);
	void ButtonRelease(const MenuPlayer player);

	void add(const Button button, std::unique_ptr<Command> command);
	void drawMenu()const;
	void displayRules()const;
	void action(const sf::Vector2f& location) const;

	void choosePlayer(const MenuPlayer player);
	const sf::Sprite getPlayer(const MenuPlayer player) const;
	std::vector<GameTextures> getPlayerTextures() const;



private:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	sf::Sprite m_title;

	//arrays
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_instructionsPage[INSTRUCTIONS];
	sf::Sprite m_players[MENU_PLAYER];
	MenuPlayer m_player;

	void setPosition();


	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;

};
