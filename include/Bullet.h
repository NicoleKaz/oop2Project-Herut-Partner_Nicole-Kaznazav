#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "MovingObject.h" 
#include "Resources.h" 


class Bullet : public MovingObject
{
public:
    Bullet(b2World& world, const GameTextures texture, const sf::Vector2f position);
	~Bullet();    
    virtual void update() override; 
    virtual void updateDirection() override {}
    virtual void move() override {}
    void draw(sf::RenderWindow& window) const;
    bool isAlive() const;

private:
    sf::Sprite m_sprite;
    b2Body* m_body;
    bool m_alive;
};

