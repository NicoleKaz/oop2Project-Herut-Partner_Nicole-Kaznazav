#include "ChaserEnemy.h"
#include <random>

// מחולל מספרים רנדומלי
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 1);

ChaserEnemy::ChaserEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location)
    : Enemy(world, texture, location), m_speed(5.0f), m_shouldChangeDirection(false)
{
    m_direction[Right] = dis(gen); // בחירת כיוון רנדומלי בתחילת הדרך
    m_direction[Left] = !m_direction[Right];
}

void ChaserEnemy::updateDirection()
{
    if (m_shouldChangeDirection)
    {
        m_direction[Right] = !m_direction[Right];
        m_direction[Left] = !m_direction[Left];
        m_shouldChangeDirection = false;
    }
}

void ChaserEnemy::move()
{
    // עדכון כיוון התנועה לפי התנגשות
    updateDirection();

    if (m_direction[Right])
    {
        float currentSpeedY = m_object_body->GetLinearVelocity().y;
        m_object_body->SetLinearVelocity({ ENEMY_MOVEMENT_SPEED, currentSpeedY });
    }
    else
    {
        float currentSpeedY = m_object_body->GetLinearVelocity().y;
        m_object_body->SetLinearVelocity({ -ENEMY_MOVEMENT_SPEED, currentSpeedY });
    }
    m_object.setPosition(SCALE * m_object_body->GetPosition().x, SCALE * m_object_body->GetPosition().y);
}

void ChaserEnemy::notifyCollision()
{
    m_shouldChangeDirection = true;
}

bool ChaserEnemy::m_object1 = Factory<MovingObject>::registerObject(ENEMY1_COLOR,
    [](b2World& world, sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<ChaserEnemy>(world, Enemy1, location);
    });
