#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "StaticObject.h"
#include "Resources.h"
#include "Factory.h"


class Floor : public StaticObject
{
public:
	Floor(b2World& world, const GameTextures texture, const sf::Vector2f location);

private:
	static bool m_object1;
	static bool m_object2;
	static bool m_object3;
	static bool m_object4;
	static bool m_object5;
	static bool m_object6;
	static bool m_object7;
	static bool m_object8;
	static bool m_object9;

};
