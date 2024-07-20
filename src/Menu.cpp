#include "Menu.h"


//This functions define the arrays
Menu::Menu(sf::RenderWindow& window)
	:m_window(window),m_score_table(window)
{
	//background sprite
	m_background.setTexture(Resources::instance().getMenuTexture(menuBackground));
	m_background.scale(1.5f, 1.4f);
	//title sprite
	m_title.setTexture(Resources::instance().getMenuTexture(Title));
	//the menu buttons
	for (int button = PLAY; button <= MUTE_MUSIC ; button++)
	{
		m_buttons[button].setTexture(Resources::instance().getButton((Button)button));
	}
	//the Pause
	for (int pause = RESUME; pause <= MUTE; pause++)
	{
		m_pauses[pause].setTexture(Resources::instance().getPause((Pause)pause));
	}
	//the instruction page 
	for (int instruction = GAME_RULES; instruction <= GAME_RULES; instruction++)
	{
		m_instructionsPage[instruction].setTexture(Resources::instance().getInstruction((Instructions)instruction));
	}
	setPosition();
}

void Menu::drawScoreTable()
{
	m_score_table.draw();
}

void Menu::updateScoreTable(const std::string& username, const int score)
{
	m_score_table.addScore(username, score);
	m_score_table.saveScores("scores.txt");
}

//This function changes the color of the button as soon as the user hovers over it with the mouse
void Menu::ButtonPress(const MenuPlayer player)
{
	m_players[player].setColor(sf::Color::Color(255, 255, 255, 255));

}

void Menu::ButtonPress(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 255));
}

void Menu::ButtonRelease(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 100));
}


//This function changes the color of the button as soon as the user removes the mouse from the button
void Menu::ButtonRelease(const MenuPlayer player)
{
	m_players[player].setColor(sf::Color::Color(255, 255, 255, 100));
};

//The players Textures
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
		return { Fourth_Player, Fourth_Speed, Fourth_Shield, Fourth_Fly };
	default:
		return { First_Player, First_Speed, First_Shield, First_Fly };
	}
}


void Menu::choosePlayer(const MenuPlayer player)
{
	m_player = player;
}

sf::Sprite Menu::getPause(const Pause object) const
{
	return m_pauses[object];
}

void Menu::displayPauseMenu() const
{
	for (const auto& option : m_pauses)
	{
		m_window.draw(option);
	}
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
	m_window.draw(m_title);
	for (const auto& option : m_buttons)
	{
		m_window.draw(option);
	}
}


// function handles user interactions with menu items by executing 
//associated actions when the user clicks on a menu item. 
//It checks if the click location falls within the bounds of any menu item
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
	for (int inst = GAME_RULES; inst <= GAME_RULES; inst++)
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
	
	m_buttons[MUTE_MUSIC].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[MUTE_MUSIC].getTextureRect().width) * 1,
		WINDOW_HEIGHT - m_buttons[MUTE_MUSIC].getTextureRect().height * 4));


	//set the pauses all in line ona after another in the middle of the screen

	m_pauses[RESUME].setPosition(sf::Vector2f((WINDOW_WIDTH - m_pauses[RESUME].getTextureRect().width) * 0.5,
		(WINDOW_HEIGHT - m_pauses[RESUME].getTextureRect().height) * 0.15));

	m_pauses[MAIN_MENU].setPosition(sf::Vector2f((WINDOW_WIDTH - m_pauses[MAIN_MENU].getTextureRect().width) * 0.5,
		(WINDOW_HEIGHT - m_pauses[MAIN_MENU].getTextureRect().height) * 0.5));

	m_pauses[MUTE].setPosition(sf::Vector2f((WINDOW_WIDTH - m_pauses[MUTE].getTextureRect().width) * 0.5,
		(WINDOW_HEIGHT - m_pauses[MUTE].getTextureRect().height) * 0.9));

	
	m_title.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.18, WINDOW_HEIGHT * 0.1));
	m_title.scale(sf::Vector2f(WINDOW_WIDTH * 0.67 / m_title.getTextureRect().width,
		WINDOW_WIDTH * 0.5 / m_title.getTextureRect().width));

	m_instructionsPage[GAME_RULES].setPosition(sf::Vector2f(WINDOW_WIDTH * 0.04f, WINDOW_HEIGHT * 0.04f));
}


