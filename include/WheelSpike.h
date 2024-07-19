#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "MovingObject.h"
#include "Resources.h"
#include "Factory.h"


class WheelSpike : public MovingObject
{
public:
    WheelSpike(b2World&, const GameTextures, const sf::Vector2f);
    void move();
    void updateDirection();

private:
    GameTextures m_wheel_textures;
    static bool m_object1;
    float m_degrees;
};