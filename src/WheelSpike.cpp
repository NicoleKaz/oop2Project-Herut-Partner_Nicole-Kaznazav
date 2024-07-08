#include "WheelSpike.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

constexpr double DEGREES_TO_RADIANS = M_PI / 180.0;

bool WheelSpike::m_object1 = Factory<MovingObject>::registerObject(WHEEL_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<WheelSpike>(world, Wheel, location);
    }
);

WheelSpike::WheelSpike(b2World& world, const GameTextures textures, const sf::Vector2f location)
    : MovingObject(world, textures, location),
    m_wheel_textures(textures), m_degrees(0.0f)
{
}

void WheelSpike::move()
{
    // Update physics rotation in Box2D 
    float angleInRadians = static_cast<float>(m_degrees * DEGREES_TO_RADIANS);
    m_object_body->SetTransform(m_object_body->GetPosition(), angleInRadians);

    // Update sprite rotation in SFML 
    m_object.setRotation(m_degrees);
}

void WheelSpike::updateDirection()
{
    m_degrees += 5.0f; // Increment the rotation angle
}
