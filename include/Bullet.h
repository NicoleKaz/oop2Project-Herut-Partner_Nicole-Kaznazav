#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h" // Assuming this provides access to game textures
#include "MovingObject.h" 


class Bullet : public MovingObject
{
public:
    Bullet(b2World& world, const GameTextures texture, const sf::Vector2f position);
	~Bullet();    
    void update(); // Update bullet's position or perform any necessary logic
    void draw(sf::RenderWindow& window) const;
    bool isAlive() const;
    virtual void updateDirection() override {}
    virtual void move() override {}

private:
    sf::Sprite m_sprite;
    b2Body* m_body;
    bool m_alive;
};

