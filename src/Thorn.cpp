#include "Thorn.h"


Thorn::Thorn(b2World& world, const GameTextures texture, const sf::Vector2f location)
	:StaticObject(world, texture, location)
{
}

//register all the spikes to the static object factory
bool Thorn::m_object1 = Factory<StaticObject>::registerObject(THORN_RED,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, ThornRed, location); }
);

bool Thorn::m_object2 = Factory<StaticObject>::registerObject(THORN_PINK,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, ThornPink, location); }
);

bool Thorn::m_object3 = Factory<StaticObject>::registerObject(THORN_BLUE,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, ThornBlue, location); }
);

bool Thorn::m_object4 = Factory<StaticObject>::registerObject(THORNS_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Thorn>(world, Thorns, location); }
);