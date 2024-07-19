#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>
#include <chrono>
#include <cstdlib>  // for std::rand() and std::srand()
#include <ctime>    // for std::time>
#include "MovingObject.h"
#include "GameObject.h"
#include "Resources.h"
#include "Factory.h"
#include "Bullet.h"
#include "Enemy.h"


class ShooterEnemy : public Enemy {
public:
    ShooterEnemy(b2World& world,  const GameTextures texture, const sf::Vector2f location);
    virtual void updateDirection() override;
    virtual void move() override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual void update() override;
    void shoot();

private:
    sf::Clock m_shootClock;
    float m_shootInterval; 
	float m_bulletSpeed; 
    static bool m_object1;
    b2World& m_world;
    std::unique_ptr<Bullet> m_bullet;
};
