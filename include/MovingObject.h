#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "GameObject.h"
#include "Resources.h"


class MovingObject : public GameObject
{
public:
	MovingObject( b2World&, const GameTextures, const sf::Vector2f);
	const b2Vec2 getPosition()const;
	virtual void update();
	virtual void updateDirection() = 0;
	virtual void move() = 0;
};