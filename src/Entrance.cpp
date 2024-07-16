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
    // בדיקה ועדכון של m_disabled
    if (m_disabled && m_disableClock.getElapsedTime().asSeconds() > 2.0f)
    {
        m_disabled = false;
    }
}


void Entrance::changeColorTemporarily(const sf::Color& color)
{
    if (!m_disabled)
    {
        m_object.setColor(color);
        m_colorChanged = true;
        m_colorChangeClock.restart();
        m_disabled = true;
        m_disableClock.restart();
    }
}



//register all the spikes to the static object factory
bool Entrance::m_object1 = Factory<StaticObject>::registerObject(GATE_GRAVITY_CHANGE_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
        return std::make_unique<Entrance>(world, GateGravityChange, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

//register all the spikes to the static object factory
bool Entrance::m_object2 = Factory<StaticObject>::registerObject(GATE_NO_FLY_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
        return std::make_unique<Entrance>(world, GateNoFly, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);

//register all the spikes to the static object factory
bool Entrance::m_object3 = Factory<StaticObject>::registerObject(GATE_END_LEVEL_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<StaticObject> {
        return std::make_unique<Entrance>(world, GateLevelEnd, location/*, false, (GameAnimations)0, (GameTextures)0*/); }
);


