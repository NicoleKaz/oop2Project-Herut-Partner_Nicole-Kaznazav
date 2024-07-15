#include "ShooterEnemy.h"

ShooterEnemy::ShooterEnemy(b2World& world, const GameTextures texture, const sf::Vector2f location)
    : Enemy(world, texture, location), m_world(world)
{
	m_shootClock.restart();
}

void ShooterEnemy::shoot()
{
    static int counter = 0; 
    if (m_shootClock.getElapsedTime().asSeconds() > 1.f)
    {
		m_shootClock.restart();
        //counter = 0;
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
    // אין צורך לעדכן כיוון
}

void ShooterEnemy::move()
{
    //shoot
    shoot();
    //m_shootClock.restart();
}

void ShooterEnemy::draw(sf::RenderWindow& window) const
{
	if (m_bullet != nullptr)
	{
		//if the time passed from the last shoot is bigger than the interval
		//if (m_shootClock.getElapsedTime().asSeconds() > 2)
		//{
            // ציור האויב
            m_bullet->draw(window);
			//restart the clock
  		//}
	}
    Enemy::draw(window);
}

bool ShooterEnemy::m_object1 = Factory<MovingObject>::registerObject(ENEMY2_COLOR,
    [](b2World& world, const sf::Vector2f location) -> std::unique_ptr<MovingObject> {
        return std::make_unique<ShooterEnemy>(world, Enemy2, location);
    });

