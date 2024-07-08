#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h"
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(b2World&, const GameTextures, const sf::Vector2f);
	virtual ~StaticObject();
	const GameTextures getType()const;

	void setDelete();
	const bool getDelete() const;


private:


protected:
	bool m_delete = false;
	//bool m_active = true;
	//bool m_fixture_destroyed = false;
	GameTextures m_type;
};
