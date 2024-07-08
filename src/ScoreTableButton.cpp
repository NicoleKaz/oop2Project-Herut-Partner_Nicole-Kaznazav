#pragma once

#include "ScoreTableButton.h"
#include "Controller.h"
//#include "WithoutYouButton.h"
//#include "GreyhoundButton.h"
//#include "OnlyTheHorsesButton.h"
//#include "SpectreButton.h"


ScoreTableButton::ScoreTableButton(Controller* game, sf::RenderWindow& window, GameManager* manager)
	:Command(game, window,manager)
{
	//adding buttons to the submenu
	//m_levels_menu.add(WithoutYou, std::make_unique<WithoutYouButton>(m_game, m_window));
	//m_levels_menu.add(Greyhound, std::make_unique<GreyhoundButton>(m_game, m_window));
	//m_levels_menu.add(OnlyTheHorses, std::make_unique<OnlyTheHorsesButton>(m_game, m_window));
	//m_levels_menu.add(Spectre, std::make_unique<SpectreButton>(m_game, m_window));
}

void ScoreTableButton::execute()
{
	// כאשר לוחצים על כפתור המשחק, הפונקציה תבצע את הפעולות הנדרשות להתחלת המשחק
}
