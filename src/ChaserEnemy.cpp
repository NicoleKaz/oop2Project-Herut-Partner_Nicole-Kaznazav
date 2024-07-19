#include "ChaserEnemy.h"
#include <random>


//snippet sets up a random number generator to produce uniformly distributed 
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 1);

ChaserEnemy::ChaserEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location, const bool up)
    : Enemy(world, texture, location), m_speed(5.0f), m_shouldChangeDirection(false), m_up(up)
{
    //snippet assigns random directions to a game object's movement
    m_direction[Right] = dis(gen); 
    m_direction[Left] = !m_direction[Right];

    //attaching the object to the floor and rotate hin according to his location
    if (m_up)
    {
        m_attach = -1.f;
    }
    else
    {
        m_attach = 1.f;
    }
    //cancel the physisc gravity powers
    m_object_body->SetGravityScale(0.0f);
}

//This function checks whether the direction should be changed and if so updates the new direction
void ChaserEnemy::updateDirection()
{
    if (m_shouldChangeDirection)
    {
        m_direction[Right] = !m_direction[Right];
        m_direction[Left] = !m_direction[Left];
        m_shouldChangeDirection = false;
    }
}

//This function updates the direction of the enemy according to the collisions that happen to him
void ChaserEnemy::move()
{
    updateDirection();
    sf::Vector2f scale = m_object.getScale();
    if (m_direction[Right])
    {
        //Changing the sprite
        if (m_rot)
        {
            m_object.setScale(std::abs(scale.x), scale.y);
            m_rot = false;
        }
        m_object_body->SetLinearVelocity({ ENEMY_MOVEMENT_SPEED, m_attach });
    }
    else
    {
        //Changing the sprite
        m_object.setScale(-std::abs(scale.x), scale.y);
        m_rot = true;
        m_object_body->SetLinearVelocity({ -ENEMY_MOVEMENT_SPEED, m_attach });
    }
    m_object.setPosition(SCALE * m_object_body->GetPosition().x, SCALE * m_object_body->GetPosition().y);
}

//returns the current state of the collision
void ChaserEnemy::notifyCollision()
{
    m_shouldChangeDirection = true;
}

//factory
bool ChaserEnemy::m_object1 = Factory<MovingObject>::registerObject(ENEMY1_COLOR,
    [](b2World& world, sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<ChaserEnemy>(world, Enemy1, location, false);
    });

bool ChaserEnemy::m_object2 = Factory<MovingObject>::registerObject(ENEMY3_COLOR,
    [](b2World& world, sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<ChaserEnemy>(world, Enemy3, location, true);
    });