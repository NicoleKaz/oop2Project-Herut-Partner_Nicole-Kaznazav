#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <cstdlib>  // for std::rand() and std::srand()
#include <ctime>    // for std::time>
#include <chrono>
#include "Resources.h"
#include "MovingObject.h"
#include "GameObject.h"
//#include "Animation.h"
#include "Factory.h"


class ChaserEnemy : public Enemy 
{
public:
    ChaserEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location, const bool up);

    void updateDirection() override;
    void move() override;
    void notifyCollision();
    //void update(float deltaTime);

private:
    bool m_direction[2] = { true, false } ;
    float m_speed;
    static bool m_object1;
    static bool m_object2;
    float m_attach;
    bool m_up;
    bool m_rot = false;
	bool m_shouldChangeDirection = false;

};
