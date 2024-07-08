#pragma once

#include "Thorn.h"


Thorn::Thorn(b2World& world, const GameTextures texture, const sf::Vector2f location/*, const bool up,
	const GameAnimations, const GameTextures*/)
	:StaticObject(world, texture, location)
{
	/*if (up)
	{
		m_object.rotate(180);
	}*/
}


//register all the spikes to the static object factory
bool Thorn::m_object1 = Factory<StaticObject>::registerObject(THORN1_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, Thorn1, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

//register all the spikes to the static object factory
bool Thorn::m_object2 = Factory<StaticObject>::registerObject(THORN2_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, Thorn2, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

bool Thorn::m_object3 = Factory<StaticObject>::registerObject(THORNS_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, Thorns, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);