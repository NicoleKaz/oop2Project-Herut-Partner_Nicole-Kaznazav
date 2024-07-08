#pragma once

#include "Entrance.h"


Entrance::Entrance(b2World& world, const GameTextures texture, const sf::Vector2f location/*, const bool up,
	const GameAnimations, const GameTextures*/)
	:StaticObject(world, texture, location)
{
    // הגדרת הגוף כ-sensor
    b2Fixture* fixture = m_object_body->GetFixtureList();
    if (fixture)
    {
        fixture->SetSensor(true);

    }

    m_originalColor = m_object.getColor();


}


void Entrance::update()
{
    if (m_colorChanged)
    {
        // בדיקת אם עברו 2 שניות
        if (m_colorChangeClock.getElapsedTime().asSeconds() > 2.0f)
        {
            // החזרת הצבע המקורי
            m_object.setColor(m_originalColor);
            m_colorChanged = false;
        }
    }
}

void Entrance::changeColorTemporarily(const sf::Color& color)
{
    m_object.setColor(color);
    m_colorChanged = true;
    m_colorChangeClock.restart();
}

//register all the spikes to the static object factory
bool Entrance::m_object1 = Factory<StaticObject>::registerObject(GATE3_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Entrance>(world, Gate3, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

//register all the spikes to the static object factory
bool Entrance::m_object2 = Factory<StaticObject>::registerObject(GATE2_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Entrance>(world, Gate2, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

//register all the spikes to the static object factory
bool Entrance::m_object3 = Factory<StaticObject>::registerObject(GATE5_COLOR,
	[](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
		return std::make_unique<Entrance>(world, Gate5, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);


