#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include "Resources.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "Floor.h"
#include "Coin.h"
#include "Thorn.h"
#include "Jumper.h"
#include "GdContactListener.h"
#include "Enemy.h"
#include "Entrance.h"
#include "ChaserEnemy.h"
#include "ShooterEnemy.h"
#include "Menu.h"
#include "Bullet.h"

class Board
{
public:

    Board(sf::RenderWindow& window, const std::vector<GameTextures> player_textures);
    void switchPlayer(const std::vector<GameTextures>& player_textures);
    bool handleInput(const sf::Event& event);
    void drawBoard();
    void createLevel(const GameMaps level, const GameBackground back/*, const GameSounds sound*/);
    void findObjectColor(const sf::Color& color, const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void addMovingObject(std::unique_ptr<MovingObject> object);
    void addMovingObject2(std::unique_ptr<MovingObject> object);
    void addStaticObject(std::unique_ptr<StaticObject> object);
    void addMovingObject(const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void addStaticObject(const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source);
    void moveObjects();
    const b2Vec2 getPlayerPosition() const;
    void viewBackground(const float addition);
    int getCoins() const;
    void updateMovingDirections()const;
    void resetBoard();
    void rightReleased() const;
    void leftReleased() const;
    void spaceReleased() const;
    void handleCollision();

	bool isWin() const { return m_win; }


private:

    sf::RenderWindow& m_window;
    b2Vec2 m_gravity;
    b2World m_world;
    std::vector<GameTextures> m_player_textures;

    //game objects:
    std::vector < std::unique_ptr< MovingObject>>  m_moving_objects;
    std::vector < std::unique_ptr< StaticObject>>  m_static_objects;

    std::vector<std::unique_ptr<Coin>> m_collected_coins;
    std::vector<std::unique_ptr<Coin>> m_initial_coins;

    sf::Sprite m_background;
    Player* m_player = nullptr;
    sf::Vector2f m_player_location;
    
    GdContactListener m_contact_listener;

    bool m_win = false;
//    sf::Sound m_game_song;


};