#pragma once

#include "LevelsMenu.h"
#include <iostream>

LevelsMenu::LevelsMenu(Controller* game, sf::RenderWindow& window, GameManager* manager)
	: m_game(game), m_window(window) , m_manager(manager)
{
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.6f, 1.6f);

	for (int button = level1; button <= level3; button++)
	{
		m_menuLevel[button].setTexture(Resources::instance().getLevelsMenu((MenuLevels)button));
	}
	locateObjects();
}


void LevelsMenu::drawLevelsMenu() const
{
	m_window.draw(m_background);
	for (int level = 0; level < m_options.size(); level++)
	{
		m_window.draw(m_menuLevel[level]);
	}
}

void LevelsMenu::handleMouseMoved(const sf::Vector2f location)
{

	// מציין את המיקום של העכבר
	for (std::size_t level = 0; level < m_options.size(); ++level)
	{


		if (m_options[level].first.getGlobalBounds().contains(location))
		{

			// הפיכת הכפתור לבולט
			m_menuLevel[level].setColor(sf::Color::Color(255, 255, 255, 150));
		}
		else
		{
			// הסרת ההבלטה מהכפתור
			m_menuLevel[level].setColor(sf::Color::Color(255, 255, 255));
		}
	}
}


const int LevelsMenu::getOptionFromUser(const sf::Vector2f location) const
{
	//check if the button contains the click location 
	for (int button = level1; button < m_options.size(); button++)
	{
		if (m_options[button].first.getGlobalBounds().contains(location))
		{
			//return the button we clicked at
			return button;
		}
	}
	//no button
	return m_options.size() + 1;
}

void LevelsMenu::action(const sf::Vector2f& location)const
{

	//check if the button contains the click location
	 for (int button = level1; button < m_options.size(); button++)
	 {
		 //why cannot enter to if?
		 if (m_options[button].first.getGlobalBounds().contains(location))
		 {

		//perform the button action
		 m_options[button].second->execute();
		 return;
		 }

	 }
}



void LevelsMenu::add(const MenuLevels button, std::unique_ptr<Command> command)
{
	//adding new button to the menu
	m_options.emplace_back(option(m_menuLevel[button], move(command)));
}

void LevelsMenu::locateObjects()
{
	//level buttons
	m_menuLevel[level1].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level1].getTextureRect().width) * 0.15,
		(WINDOW_HEIGHT - m_menuLevel[level1].getTextureRect().height) * 0.25));

	m_menuLevel[level2].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level2].getTextureRect().width) * 0.90,
		(WINDOW_HEIGHT - m_menuLevel[level2].getTextureRect().height) * 0.25));

	m_menuLevel[level3].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level3].getTextureRect().width) * 0.50,
		(WINDOW_HEIGHT - m_menuLevel[level3].getTextureRect().height) * 0.75));

	/*m_menuLevel[Spectre].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[Spectre].getTextureRect().width) * 0.75,
		(WINDOW_HEIGHT - m_menuLevel[Spectre].getTextureRect().height) * 0.75));*/
}
