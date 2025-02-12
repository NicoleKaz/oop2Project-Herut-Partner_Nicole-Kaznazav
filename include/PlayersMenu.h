#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Resources.h"
#include "Command.h"


class PlayersMenu 
{
public:
    PlayersMenu(sf::RenderWindow& window);
    void drawPlayer() const;
    void add(const MenuPlayer player, std::unique_ptr<Command> command);
    void handleAction(const sf::Vector2f& location);
    void handleSwitchPlayerMouseMoved(const sf::Vector2f& location);

private:
    sf::RenderWindow& m_window;
    sf::Sprite m_background;
    sf::Sprite m_player[MENU_PLAYER];
    void locateObjects();
    typedef std::pair< sf::Sprite, std::unique_ptr<Command>> options;
    std::vector<options> m_options;
};
