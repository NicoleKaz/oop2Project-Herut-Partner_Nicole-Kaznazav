#include "Menu.h"
#include <iostream>


//This functions define the arrays
Menu::Menu(sf::RenderWindow& window)
	:m_window(window)
{
	//background sprite
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.5f, 1.4f);
	//title sprite
	m_title.setTexture(Resources::instance().getMenuTexture(Title));//??
	//the menu buttons
	for (int button = PLAY; button <= EXIT; button++)
	{
		m_buttons[button].setTexture(Resources::instance().getButton((Button)button));
	}
	//the instruction page 
	for (int instruction = GAME_RULES; instruction <= STICKER; instruction++)
	{
		m_instructionsPage[instruction].setTexture(Resources::instance().getInstruction((Instructions)instruction));
	}
	setPosition();
}

sf::Sprite Menu::getButton(const Button button) const
{
	return m_buttons[button];
}


//This function changes the color of the button as soon as the user hovers over it with the mouse
void Menu::ButtonPress(const MenuPlayer player)
{
	m_players[player].setColor(sf::Color::Color(255, 255, 255, 255));

}

//This function changes the color of the button as soon as the user removes the mouse from the button
void Menu::ButtonRelease(const MenuPlayer player)
{
	m_players[player].setColor(sf::Color::Color(255, 255, 255, 100));
}


std::vector<GameTextures> Menu::getPlayerTextures() const
{
	switch (m_player)
	{
	case PLAYER1:
		return { First_Player, First_Speed, First_Shield, First_Fly };
	case PLAYER2:
		return { Second_Player, Second_Speed, Second_Shield, Second_Fly };
	case PLAYER3:
		return { Third_Player, Third_Speed, Third_Shield, Third_Fly };
	case PLAYER4:
		return { Fourth_Player, Fourth_Speed, Fourth_Player, Fourth_Fly };
	default:
		return { First_Player, First_Speed, First_Shield, First_Fly };
	}
}


void Menu::choosePlayer(const MenuPlayer player)
{
	m_player = player;
}

const sf::Sprite Menu::getPlayer(const MenuPlayer player) const
{
	//return the sprite
	return m_players[player];
}




//adding new button to the menu
void Menu::add(const Button button, std::unique_ptr<Command> command)
{
	m_options.push_back(std::make_pair(m_buttons[button], std::move(command)));
}



//draw the game menu
void Menu::drawMenu()const
{
	m_window.draw(m_background);
	for (const auto& option : m_options)
	{
		m_window.draw(option.first);
	}
	m_window.draw(m_title);
}


void Menu::action(const sf::Vector2f& location) const
{
	for (const auto& option : m_options)
	{
		if (option.first.getGlobalBounds().contains(location))
		{
			option.second->execute();
		}
	}
}



//this function showes the instructions page after the press
void Menu::displayRules()const
{
	m_window.draw(m_background);
	for (int inst = GAME_RULES; inst <= STICKER; inst++)
	{
		m_window.draw(m_instructionsPage[inst]);
	}
}

//this function set the position 
//this function set the position of the buttons and the title in the menu
void Menu::setPosition()
{
	//set the buttons
	m_buttons[PLAY].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 3.5));

	m_buttons[HELP].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.75,
		WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 4));;

	m_buttons[SWITCH_PLAYER].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[SWITCH_PLAYER].getTextureRect().width) * 0.25,
		WINDOW_HEIGHT - m_buttons[SWITCH_PLAYER].getTextureRect().height * 4));
	

	m_buttons[SCORE_TABLE].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[SCORE_TABLE].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[SCORE_TABLE].getTextureRect().height * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 1,
		WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1));
	
	m_title.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.18, WINDOW_HEIGHT * 0.1));
	m_title.scale(sf::Vector2f(WINDOW_WIDTH * 0.67 / m_title.getTextureRect().width,
		WINDOW_WIDTH * 0.5 / m_title.getTextureRect().width));

	m_instructionsPage[GAME_RULES].setPosition(sf::Vector2f(WINDOW_WIDTH * 0.120f, WINDOW_HEIGHT * 0.10f));
	m_instructionsPage[STICKER].setPosition(sf::Vector2f((WINDOW_WIDTH - m_instructionsPage[STICKER].getTextureRect().width) * 0.9,
		WINDOW_HEIGHT - m_instructionsPage[STICKER].getTextureRect().height * 1.0));
}

////Returns the from the array
//sf::Sprite Menu::getInstructions(const Instructions object) const
//{
//	return m_instructionsPage[object];
//}

