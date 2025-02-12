﻿#include "Coin.h"


Coin::Coin(b2World& world, const GameTextures texture, const sf::Vector2f location)
	:StaticObject(world, texture, location)
{
}

//register the coin to the static object factory
bool Coin::m_object1 = Factory<StaticObject>::registerObject(COIN_COLOR_SCORE,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinScore, location); }
);

//register the coin to the static object factory
bool Coin::m_object2 = Factory<StaticObject>::registerObject(COIN_COLOR_SPEED,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinSpeed, location); }
);

//register the coin to the static object factory
bool Coin::m_object3 = Factory<StaticObject>::registerObject(COIN_COLOR_SHIELD,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinShield, location); }
);

//register the coin to the static object factory
bool Coin::m_object4 = Factory<StaticObject>::registerObject(COIN_COLOR_FLY,
	[](b2World& world, sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Coin>(world, GameTextures::CoinFly, location); }
);

