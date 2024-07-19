#include "ShooterEnemy.h"


ShooterEnemy::ShooterEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location)
    : Enemy(world, texture, location), m_world(world)
{
	m_shootClock.restart();
    //cancel the physisc gravity powers
    m_object_body->SetGravityScale(0.0f);
}

void ShooterEnemy::shoot()
{
    static int counter = 0; 
    if (m_shootClock.getElapsedTime().asSeconds() > 1.35f)
    {
		m_shootClock.restart();
        // Implement shooting logic
        sf::Vector2f bulletPosition = m_object.getPosition();
        bulletPosition.x += 50; // Adjusting bullet position slightly
        //if is NULPTR
        if (m_bullet != nullptr)
        {
            // Destroy the bullet
            m_world.DestroyBody(m_bullet->getBody());
        }
        // Create a new bullet and add it to the list
        m_bullet.reset(new Bullet(m_world, Bullet1, bulletPosition));
    }
}

void ShooterEnemy::update()
{
    if (m_bullet)
    {
        // Update the bullet's position
        m_bullet->update();
    }
    MovingObject::update();
}

void ShooterEnemy::updateDirection() 
{
}

void ShooterEnemy::move()
{
    shoot();
}

void ShooterEnemy::draw(sf::RenderWindow& window) const
{
	if (m_bullet != nullptr)
	{
        m_bullet->draw(window);
	}
    Enemy::draw(window);
}

bool ShooterEnemy::m_object1 = Factory<MovingObject>::registerObject(ENEMY2_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<ShooterEnemy>(world, Enemy2, location);
    });

