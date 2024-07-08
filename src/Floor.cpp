#pragma once

#include "Floor.h"


Floor::Floor(b2World& world, const GameTextures texture, const sf::Vector2f location/*,const bool, const GameAnimations, const GameTextures*/)
	:StaticObject(world, texture, location)
{
}

//register all the bricks to the static object factory
bool Floor::m_object1 = Factory<StaticObject>::registerObject(CUBE1_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube1, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

//register all the bricks to the static object factory
bool Floor::m_object2 = Factory<StaticObject>::registerObject(CUBE2_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube2, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

bool Floor::m_object3 = Factory<StaticObject>::registerObject(FLOOR_Inair_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Floor_Inair, location/*, false, (GameAnimations)0, (GameTextures)0*/); });

bool Floor::m_object4 = Factory<StaticObject>::registerObject(HELF_CUBE_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Helfcube, sf::Vector2f(location.x, location.y + 13)/*, false,
		(GameAnimations)0, (GameTextures)0)*/); });

