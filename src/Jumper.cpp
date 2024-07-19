#pragma once

#include "Jumper.h"

Jumper::Jumper(b2World& world, const GameTextures texture, const sf::Vector2f location)
	:StaticObject(world, texture, location)
{
}

//register all the jumpers to the static object factory
bool Jumper::m_object1 = Factory<StaticObject>::registerObject(JUMPER1_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Jumper>(world, Jumper1, sf::Vector2f(location.x, location.y + 13)); }
);
bool Jumper::m_object2 = Factory<StaticObject>::registerObject(JUMPER2_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Jumper>(world, Jumper2, location); }
);