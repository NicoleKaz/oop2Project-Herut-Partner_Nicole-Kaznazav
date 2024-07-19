#include "LevelsMenu.h"


LevelsMenu::LevelsMenu(sf::RenderWindow& window, GameManager& manager)
	:m_window(window), m_manager(manager)
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

//This function handles mouse movement events 
void LevelsMenu::handleMouseMoved(const sf::Vector2f location)
{

	// Loop through each menu item
	for (std::size_t level = 0; level < m_options.size(); ++level)
	{
		if (m_options[level].first.getGlobalBounds().contains(location))
		{
			// Change color when mouse is over the item
			m_menuLevel[level].setColor(sf::Color::Color(255, 255, 255, 150));
		}
		else
		{
			// Reset color when mouse is not over the item
			m_menuLevel[level].setColor(sf::Color::Color(255, 255, 255));
		}
	}
}

//This function checking where the user clicked
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

//This function determines which menu button was clicked based on the location of the click and performs the corresponding action
void LevelsMenu::action(const sf::Vector2f& location)const
{
	//check if the button contains the click location
	for (int button = level1; button < m_options.size(); button++)
	{
		if (m_options[button].first.getGlobalBounds().contains(location))
		{
			//perform the button action
			m_options[button].second->execute();
			return;
		}
	}
}

//This function adding new button to the menu
void LevelsMenu::add(const MenuLevels button, std::unique_ptr<Command> command)
{
	m_options.emplace_back(option(m_menuLevel[button], move(command)));
}


void LevelsMenu::locateObjects()
{
	//level buttons
	m_menuLevel[level1].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level1].getTextureRect().width) * 0.15,
		(WINDOW_HEIGHT - m_menuLevel[level1].getTextureRect().height) * 0.30));

	m_menuLevel[level2].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level2].getTextureRect().width) * 0.90,
		(WINDOW_HEIGHT - m_menuLevel[level2].getTextureRect().height) * 0.20));

	m_menuLevel[level3].setPosition(sf::Vector2f((WINDOW_WIDTH - m_menuLevel[level3].getTextureRect().width) * 0.50,
		(WINDOW_HEIGHT - m_menuLevel[level3].getTextureRect().height) * 0.75));
}
