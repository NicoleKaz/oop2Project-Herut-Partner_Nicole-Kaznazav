#pragma once

#include "Floor.h"


Floor::Floor(b2World& world, const GameTextures texture, const sf::Vector2f location/*,const bool, const GameAnimations, const GameTextures*/)
	:StaticObject(world, texture, location)
{
}

//register all the bricks to the static object factory
bool Floor::m_object1 = Factory<StaticObject>::registerObject(CUBE1_RED,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube1Red, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

//register all the bricks to the static object factory
bool Floor::m_object2 = Factory<StaticObject>::registerObject(CUBE2_RED,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube2Red, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

bool Floor::m_object3 = Factory<StaticObject>::registerObject(FLOOR_Inair_RED,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Floor_Inair_red, location/*, false, (GameAnimations)0, (GameTextures)0*/); });

bool Floor::m_object4 = Factory<StaticObject>::registerObject(FLOOR_Inair_PINK,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Floor_Inair_pink, location/*, false, (GameAnimations)0, (GameTextures)0*/); });

bool Floor::m_object5 = Factory<StaticObject>::registerObject(CUBE1_PINK,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube1Pink, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

//register all the bricks to the static object factory
bool Floor::m_object6 = Factory<StaticObject>::registerObject(CUBE2_PINK,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube2Pink, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

bool Floor::m_object7 = Factory<StaticObject>::registerObject(FLOOR_Inair_BLUE,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Floor_Inair_blue, location/*, false, (GameAnimations)0, (GameTextures)0*/); });

bool Floor::m_object8 = Factory<StaticObject>::registerObject(CUBE1_BLUE,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube1Blue, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });

//register all the bricks to the static object factory
bool Floor::m_object9 = Factory<StaticObject>::registerObject(CUBE2_BLUE,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Floor>(world, Cube2Blue, location/*, false, (GameAnimations)0, (GameTextures)0);*/); });