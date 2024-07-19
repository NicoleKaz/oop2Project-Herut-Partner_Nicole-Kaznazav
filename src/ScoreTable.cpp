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
	loadScores("scores.txt");
}

void ScoreTable::loadScores(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string username;
            int score;
            if (iss >> username >> score)
            {
                m_scores.emplace_back(username, score);
            }
        }
        file.close();
    }
}

void ScoreTable::saveScores(const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto& entry : m_scores)
        {
            file << entry.first << " " << entry.second << std::endl;
        }
        file.close();
    }
}

void ScoreTable::addScore(const std::string& username, int score)
{
    m_scores.emplace_back(username, score);
    sortScores();
    if (m_scores.size() > maxScores)
    {
        m_scores.pop_back();
    }
}

void ScoreTable::sortScores()
{
    std::sort(m_scores.begin(), m_scores.end(), [](const auto& a, const auto& b)
        {
        return a.second > b.second;
        });
}

void ScoreTable::draw()
{
    m_window.draw(m_backgroundScore);
    m_window.draw(m_titleScore);

    for (size_t i = 0; i < m_scores.size(); i++)
    {
        sf::Text text;
        text.setFont(Resources::instance().getFont());
        text.setString(m_scores[i].first + ": " + std::to_string(m_scores[i].second));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(m_table.x + 20.f, i * 40.f + 250.f);
        m_window.draw(text);
    }
}