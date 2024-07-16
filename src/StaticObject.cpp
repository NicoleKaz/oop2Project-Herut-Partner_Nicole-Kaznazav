#pragma once

#include "StaticObject.h"

StaticObject::StaticObject(b2World& world, const GameTextures texture, const sf::Vector2f location)
    :GameObject(texture, location), m_type(texture)
{
    //keep the size
    const sf::Vector2f sprite_size(m_object.getTextureRect().width, m_object.getTextureRect().height);

    //physics
    b2BodyDef bodyDef; // difine body
    bodyDef.position.Set(m_object.getPosition().x / SCALE, m_object.getPosition().y / SCALE); //locate it
    bodyDef.type = b2_staticBody; // define static

    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this); // define its pointer for the collision 
    m_object_body = world.CreateBody(&bodyDef); //pushing the body to the world

    b2PolygonShape shape; //define shapr
    shape.SetAsBox(sprite_size.x / 2.0f / SCALE, sprite_size.y / 2.0f / SCALE); // set box
    b2FixtureDef fixtureDef; // define fixture
    fixtureDef.shape = &shape;
    m_object_body->CreateFixture(&fixtureDef); //pushing to body
}

StaticObject::~StaticObject()
{
    m_object_body->DestroyFixture(m_object_body->GetFixtureList());
    m_object_body->GetWorld()->DestroyBody(m_object_body);
}

const GameTextures StaticObject::getType() const
{
    return m_type;
}

void StaticObject::setDelete()
{
    m_delete = true;
}

const bool StaticObject::getDelete()const
{
    return m_delete;
}

