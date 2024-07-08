#pragma once

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>
#include <cstdlib>  // for std::rand() and std::srand()
#include <ctime>    // for std::time>
#include <chrono>
#include "Resources.h"
#include "MovingObject.h"
#include "GameObject.h"
//#include "Animation.h"
#include "Factory.h"
#include "Bullet.h"


class ShooterEnemy : public Enemy {
public:
    ShooterEnemy(b2World& world,  const GameTextures texture, const sf::Vector2f location);
    virtual void updateDirection() override;
    virtual void move() override;
    virtual void draw(sf::RenderWindow& window) const override;
    void shoot();
private:
    sf::Clock m_shootClock;
    float m_shootInterval; // זמן בין יריות
	float m_bulletSpeed; // מהירות כדור
    static bool m_object1;
    b2World& m_world;
    std::unique_ptr<Bullet> m_bullet;



};
