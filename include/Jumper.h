#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "StaticObject.h"
#include "Resources.h"
#include "Factory.h"


class Jumper : public StaticObject
{
public:
	Jumper(b2World& world, const GameTextures texture, const sf::Vector2f location);

private:
	static bool m_object1;
	static bool m_object2;
};