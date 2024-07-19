#include "WheelSpike.h"
//#include <cmath>


WheelSpike::WheelSpike(b2World& world, const GameTextures textures, const sf::Vector2f location)
    : MovingObject(world, textures, location), m_degrees(0.0f)
{
    //cancel the physisc gravity powers
    m_object_body->SetGravityScale(0.0f);
}

void WheelSpike::move()
{
    // Update sprite rotation in SFML 
    m_object.setRotation(m_degrees);
}

void WheelSpike::updateDirection()
{
    m_degrees += 5.0f; // Increment the rotation angle
}


bool WheelSpike::m_object1 = Factory<MovingObject>::registerObject(WHEEL_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<WheelSpike>(world, Wheel, location);
    }
);
