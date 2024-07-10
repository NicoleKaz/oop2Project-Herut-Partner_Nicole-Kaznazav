#pragma once
#include "ScoreTable.h"
#include <iostream>
#include <thread>


ScoreTable::ScoreTable(sf::RenderWindow& window)
    : m_window(window) 
{

    m_backgroundScore.setTexture(Resources::instance().getMenuTexture(Score_Background));
    m_backgroundScore.scale(1.6, 1.6);

    m_table = (sf::Vector2f(WINDOW_HEIGHT / 2.f, WINDOW_WIDTH / 2.f));
        
    m_titleScore.setFont(Resources::instance().getFont());
    m_titleScore.setString("High Scores");
	m_titleScore.setCharacterSize(48);
	m_titleScore.setFillColor(sf::Color::White);
	m_titleScore.setPosition(300, 10);
}

void ScoreTable::loadScores(const std::string& filename) 
{
    std::ifstream file(filename);
    if (file.is_open())
    {
		std::cout << "File is open" << std::endl;
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            int score;
            if (iss >> score) 
            {
                m_scores.push_back(score);
            }
        }
        file.close();
    }
    sortScores();
}

void ScoreTable::saveScores(const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open()) 
    {
		std::cout << "File is open2" << std::endl;
        for (const auto& score : m_scores) 
        {
            file << score << std::endl;
        }
    }
}

void ScoreTable::addScore(int score)
{
    m_scores.push_back(score);
    sortScores();
	std::cout << "Score added" << std::endl;
    if (m_scores.size() > maxScores) 
    {
        m_scores.pop_back();
    }
}

void ScoreTable::sortScores() 
{
    std::sort(m_scores.begin(), m_scores.end(), std::greater<int>());
}

void ScoreTable::draw()
{
    m_window.draw(m_backgroundScore);
    m_window.draw(m_titleScore);

    for (size_t i = 0; i < m_scores.size(); ++i)
    {
        sf::Text text;
        text.setFont(Resources::instance().getFont());
        text.setString(std::to_string(m_scores[i]));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 50 + i * 30);
        m_window.draw(text);
    }
}