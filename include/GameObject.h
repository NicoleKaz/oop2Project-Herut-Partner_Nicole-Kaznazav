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
	//virtual ~GameObject() { m_object_body->GetWorld()->DestroyBody(m_object_body); }
	

protected:
	sf::Sprite m_object;
	b2Body* m_object_body;
	float m_attach;
	sf::Clock m_clock;


};