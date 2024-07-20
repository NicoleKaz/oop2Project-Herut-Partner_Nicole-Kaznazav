#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include "GdContactListener.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "ShooterEnemy.h"
#include "ChaserEnemy.h"
#include "Resources.h"
#include "Entrance.h"
#include "Jumper.h"
#include "Player.h"
#include "Bullet.h"
#include "Floor.h"
#include "Thorn.h"
#include "Enemy.h"
#include "Coin.h"
#include "Menu.h"


class Board
{
public:
    Board(sf::RenderWindow& window, const std::vector<GameTextures> player_textures);
    const b2Vec2 getPlayerPosition() const;
    void switchPlayer(const std::vector<GameTextures>& player_textures);
    void drawBoard();
    void createLevel(const GameMaps level, const GameBackground back);
    void findObjectColor(const sf::Color& color, const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void addMovingObject(std::unique_ptr<MovingObject> object);
    void addStaticObject(std::unique_ptr<StaticObject> object);
    void moveObjects();
    void viewBackground(const float addition);
    void updateMovingDirections()const;
    void resetBoard();
    void rightReleased() const;
    void leftReleased() const;
    void spaceReleased() const;
    void handleCollision();
    bool handleInput(const sf::Event& event);
	bool isWin() const { return m_win; }
    int getCoins() const;

private:
    //game objects:
    std::vector < std::unique_ptr< MovingObject>>  m_moving_objects;
    std::vector < std::unique_ptr< StaticObject>>  m_static_objects;
    sf::RenderWindow& m_window;
    b2Vec2 m_gravity;
    b2World m_world;
    std::vector<GameTextures> m_player_textures;
    sf::Sprite m_background;
    Player* m_player = nullptr;
    sf::Vector2f m_player_location;
    GdContactListener m_contact_listener;
    bool m_win = false;
};