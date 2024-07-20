#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Resources.h>
#include "Command.h"


class LevelsMenu
{
public:
	LevelsMenu(sf::RenderWindow&, GameManager&);
	void drawLevelsMenu()const;
	void action(const sf::Vector2f& location) const;
	void add(const MenuLevels, std::unique_ptr<Command>);
	void handleMouseMoved(const sf::Vector2f location);

private:
	GameManager& m_manager;
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	sf::Sprite m_buttons[MENU_BUTTONS];
	sf::Sprite m_menuLevel[LEVEL_MENU];
	typedef std::pair<const sf::Sprite, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	void locateObjects();
};
