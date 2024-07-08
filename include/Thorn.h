#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h"
#include "StaticObject.h"
#include "Factory.h"

class Thorn : public StaticObject
{
public:
	Thorn(b2World& world, const GameTextures texture, const sf::Vector2f location/*, const bool up,
		const GameAnimations, const GameTextures*/);

private:
	static bool m_object1;
	static bool m_object2;
	static bool m_object3;
};