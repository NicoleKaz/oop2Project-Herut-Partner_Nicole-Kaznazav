#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h"


class GameObject
{
public:
	GameObject(const GameTextures, const sf::Vector2f);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow&) const;
	b2Body* getBody() const;	

protected:
	sf::Sprite m_object;
	sf::Clock m_clock;
	b2Body* m_object_body;
	float m_attach;
};