#pragma once

#include "Board.h"
#include <thread>
//#include <ShooterEnemy.h>


Board::Board(sf::RenderWindow& window, const std::vector<GameTextures> player_textures)
:m_window(window), m_gravity(0.0f, 9.8f), m_world(m_gravity), m_player_textures(player_textures)
{
    m_background.setColor(sf::Color::White);
	m_world.SetContactListener(&m_contact_listener);
}

void Board::switchPlayer(const std::vector<GameTextures>& player_textures)
{
	m_player_textures = player_textures;
}

bool Board::handleInput(const sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyReleased:
		{
		//update the player direction
		if (event.key.code == sf::Keyboard::Right)
		{
			rightReleased();
		}
		else if (event.key.code == sf::Keyboard::Left)
		{
			leftReleased();
		}
		else if (event.key.code == sf::Keyboard::Space)
		{
			spaceReleased();
		}
		else if (event.key.code == sf::Keyboard::Escape)
		{
			return true;
		}
		break;
	}
	}
	return false;
}


int Board::getCoins() const
{
	return m_player->getCoins();
}

void Board::updateMovingDirections()const
{
	// Update each moving object's direction based on its state
	for (auto& object : m_moving_objects)
	{
		object->updateDirection();
	}
}


void Board::resetBoard()
{
	//clear vectors
	m_static_objects.clear();
	m_moving_objects.clear();
	//reset members
	m_win = false;
	m_background.setPosition(0, 0);
	m_background.setColor(sf::Color::White);

	// Destroy all fixtures
	for (b2Body* body = m_world.GetBodyList(); body; body = body->GetNext())
	{
		b2Fixture* fixture = body->GetFixtureList();
		while (fixture)
		{
			b2Fixture* next = fixture->GetNext();
			body->DestroyFixture(fixture);
			fixture = next;
		}
	}
	// Destroy all bodies
	for (b2Body* body = m_world.GetBodyList(); body;)
	{
		b2Body* next = body->GetNext();
		m_world.DestroyBody(body);
		body = next;
	}
	// Reset the player
	m_player = nullptr;
	// Reset the world
	m_world = b2World(m_gravity);
	m_world.SetContactListener(&m_contact_listener);
}


void Board::moveObjects()
{
	// Update Box2D world
	float timeStep = 1.0f / 60.0f; // Adjust the time step as needed
	int32 velocityIterations = 6; // Adjust the iterations as needed
	int32 positionIterations = 2; // Adjust the iterations as needed
	m_world.Step(timeStep, velocityIterations, positionIterations);

	for (int index = 0; index < m_moving_objects.size(); index++)
	{
		m_moving_objects[index]->move();
	}
}


void Board::leftReleased()const
{
	m_player->releaseLeft();
}

void Board::spaceReleased() const
{
	m_player->releaseSpace();
}

void Board::rightReleased()const
{
	m_player->releaseRight();
}

void Board::handleCollision()
{
	std::erase_if(m_static_objects, [](const auto& static_object) {return static_object->getDelete(); });

	if (!m_player->isAlive())
	{
		m_player->setRegularState();
		m_player->resetPlayerAfterKill();
	}
	if (m_player->isGravityChange())
	{
		m_gravity = -m_gravity;
		m_world.SetGravity(m_gravity);	
	}
	for (auto& object : m_static_objects)
	{
		if (typeid(*object) == typeid(Entrance))
		{
			static_cast<Entrance*>(object.get())->update(); //maybe need to change more nice.
		}
	}

	//for (auto& moving_object : m_moving_objects)
	//{
	//	if (typeid (*moving_object) == typeid(ShooterEnemy))
	//	{
	//		static_cast<ShooterEnemy*>(moving_object.get())->shoot(); // Execute shooting logic for ShooterEnemy
	//	}
	//}


	if (m_player->isSpeedState())	/*so*/ m_player->setSpeedState();
	if (m_player->isShieldState()) /*so*/  m_player->setShieldState();
	if (m_player->isFlystate())   /*so*/   m_player->setFlyState();

	m_player->updateTools(m_background);

	//end of the level
	if (m_player->isWinner())
	{
		m_win = true;
		m_background.setColor(sf::Color::White);
	}
}

//This function draws the board
void Board::drawBoard()
{
	m_window.draw(m_background);
	for (auto& object : m_static_objects)
	{
		object->draw(m_window);
	}
	for (auto& object : m_moving_objects)
	{
		object->draw(m_window);
	}
}

void Board::createLevel(const GameMaps level, const GameBackground back)
{
	m_background.setTexture(Resources::instance().getGameBackground(back));
	m_background.scale(1.6f, 1.6f);

    //read level board from image by pixel
    const sf::Image& m_source = Resources::instance().getMap(level);
    for (size_t y = 0; y < m_source.getSize().y; ++y)
    {
        for (size_t x = 0; x < m_source.getSize().x; ++x)
        {
            //the object location acording to the pixel location
            const sf::Vector2f location(50 * x + 25, 50 * y + 25);
			sf::Color color = m_source.getPixel(x, y);

			findObjectColor(color, location, x, y, m_source);
        }
    }
}

void Board::findObjectColor(const sf::Color& color, const sf::Vector2f& location, size_t x, size_t y, const sf::Image& m_source)
{
	if (color == sf::Color::White)
	{
		return;
	}

	//creating the player sepratly to keep a pointer on him
	else if ((color == PLAYER_COLOR))
	{
		m_player = new Player(m_world, m_player_textures, location);
		m_moving_objects.push_back(std::unique_ptr<Player>(m_player));
		m_player_location = location;
	}
	else
	{
		auto movingObject = Factory<MovingObject>::createObject(m_source.getPixel(x, y), m_world, location);
		if (movingObject)
		{
			addMovingObject(std::move(movingObject));
		}
		else
		{
			auto staticObject = Factory<StaticObject>::createObject(m_source.getPixel(x, y), m_world, location);
			if (staticObject)
			{
				addStaticObject(std::move(staticObject));
			}
		}
	}
}

void Board::addMovingObject(std::unique_ptr<MovingObject> object)
{
	m_moving_objects.push_back(std::move(object));
}

void Board::addStaticObject(std::unique_ptr<StaticObject> object)
{
	m_static_objects.push_back(std::move(object));
}

const b2Vec2 Board::getPlayerPosition()const
{
	return m_player->getPosition();
}

void Board::viewBackground(const float addition)
{
	//moving the game background
	m_background.setPosition(m_background.getPosition().x + addition, m_background.getPosition().y);
}

