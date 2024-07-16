#include "Bullet.h"

Bullet::Bullet(b2World& world, const GameTextures texture, const sf::Vector2f position)
    : MovingObject(world, texture, position), m_alive(true)
{
    // Initialize bullet sprite and physics body
    m_sprite.setTexture(Resources::instance().getGameTexture(texture));
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
    m_sprite.setPosition(position);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.position.Set(position.x / SCALE, position.y / SCALE); 
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this); // update the pointer to return himself
    m_body = world.CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = m_sprite.getLocalBounds().width / 2 / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    m_body->CreateFixture(&fixtureDef);

    // Apply impulse force to the Box2D body
    b2Vec2 forceScaled{ 120 * 8.f / SCALE, 0 };

    m_body->SetLinearVelocity(forceScaled);
    m_body->ApplyLinearImpulse(forceScaled, m_body->GetWorldCenter(), true);
}

//distractor
Bullet::~Bullet()
{
    m_body->GetWorld()->DestroyBody(m_body);
}

void Bullet::update()
{
    b2Vec2 position = m_body->GetPosition();
    m_sprite.setPosition(position.x * SCALE, position.y * SCALE);
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}

bool Bullet::isAlive() const
{
    return m_alive;
}