#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Resources.h"


class ScoreTable {
public:
    ScoreTable(sf::RenderWindow& window);
    void loadScores(const std::string& filename);
    void saveScores(const std::string& filename);
    void addScore(int score);
    void draw();

private:
    sf::Sprite m_backgroundScore;
    sf::Text m_titleScore;
    sf::RenderWindow& m_window;
    std::vector<int> m_scores;
    sf::Vector2f m_table;

    const int maxScores = 10; // Maximum number of scores to keep
    void sortScores();

};