#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "GameObject.h"
#include "Resources.h"


class StaticObject : public GameObject
{
public:
	StaticObject(b2World&, const GameTextures, const sf::Vector2f);
	virtual ~StaticObject();
	const GameTextures getType()const;
	const bool getDelete() const;
	void setDelete();
	void setNotDelete();

protected:
	bool m_delete = false;
	GameTextures m_type;
};
