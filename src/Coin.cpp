#include "Coin.h"

#pragma once

Coin::Coin(b2World& world, const GameTextures texture, const sf::Vector2f location/*,
	const bool, const GameAnimations, const GameTextures*/)
	:StaticObject(world, texture, location)
{
}

//register the coin to the static object factory
bool Coin::m_object1 = Factory<StaticObject>::registerObject(COIN_COLOR_SCORE,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinScore, location/*,
		false, (GameAnimations)0, (GameTextures)0*/); }

);

//register the coin to the static object factory
bool Coin::m_object2 = Factory<StaticObject>::registerObject(COIN_COLOR_SPEED,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinSpeed, location/*,
		false, (GameAnimations)0, (GameTextures)0*/); }
);

//register the coin to the static object factory
bool Coin::m_object3 = Factory<StaticObject>::registerObject(COIN_COLOR_Shield,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinShield, location/*,
		false, (GameAnimations)0, (GameTextures)0*/); }
);

//register the coin to the static object factory
bool Coin::m_object4 = Factory<StaticObject>::registerObject(COIN_COLOR_Fly,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinFly, location/*,
		false, (GameAnimations)0, (GameTextures)0*/); }
);