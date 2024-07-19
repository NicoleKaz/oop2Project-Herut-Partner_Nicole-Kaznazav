#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Resources.h"


class ScoreTable {
public:
    ScoreTable(sf::RenderWindow& window);
    void loadScores(const std::string& filename);
    void saveScores(const std::string& filename);
    void addScore(const std::string& username, int score);
    void draw();

private:
    sf::Sprite m_backgroundScore;
    sf::Text m_titleScore;
    sf::RenderWindow& m_window;
    std::vector<std::pair<std::string, int>> m_scores; 
    sf::Vector2f m_table;
    const int maxScores = 10; // Maximum number of scores to keep
    void sortScores();
};