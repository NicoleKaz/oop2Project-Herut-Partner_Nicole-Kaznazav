#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <cstdlib>  
#include <chrono>
#include <ctime>    
#include "MovingObject.h"
#include "GameObject.h"
#include "Resources.h"
#include "Factory.h"
#include "Enemy.h"


class ChaserEnemy : public Enemy 
{
public:
    ChaserEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location, const bool up);
    void updateDirection() override;
    void move() override;
    void notifyCollision();

private:
    static bool m_object1;
    static bool m_object2;
    float m_attach;
    float m_speed;
    bool m_up;
    bool m_rot = false;
	bool m_shouldChangeDirection = false;
    bool m_direction[2] = { true, false };
};
