#include "Board.h"
#include <thread>


//This constructor initializes the Board object with a reference to the main window,
//a vector of player textures, and sets up the Box2D world with gravity and a contact listener.
Board::Board(sf::RenderWindow& window, const std::vector<GameTextures> player_textures)
	:m_window(window), m_gravity(0.0f, 9.8f), m_world(m_gravity), m_player_textures(player_textures)
{
	m_background.setColor(sf::Color::White);
	m_world.SetContactListener(&m_contact_listener);
}

//This function changes the player's texture according to the person's choice
void Board::switchPlayer(const std::vector<GameTextures>& player_textures)
{
	m_player_textures = player_textures;
}

//This function handles the user's pressing on the keys and moves the player accordingly
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

//These functions handle the release of specific keys and are intended 
//to update the state of the player accordingly.
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

//This function returns the amount of coins the player has collected
int Board::getCoins() const
{
	return m_player->getCoins();
}

//This function updates the direction of the moving objects on the game
void Board::updateMovingDirections()const
{
	// Update each moving object's direction based on its state
	for (auto& object : m_moving_objects)
	{
		object->updateDirection();
	}
}

//This function initializes the game board
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
	m_world.SetContactListener(&m_contact_listener);
}

//This function updates the movement of the moving objects in BOX2D
void Board::moveObjects()
{
	// Update Box2D world
	float timeStep = 1.0f / 60.0f; // Adjust the time step as needed
	int32 velocityIterations = 6; // Adjust the iterations as needed
	int32 positionIterations = 2; // Adjust the iterations as needed
	m_world.Step(timeStep, velocityIterations, positionIterations);
	//vector of the moving objects.
	for (int index = 0; index < m_moving_objects.size(); index++)
	{
		m_moving_objects[index]->move();
	}
}

//This function deals with collisions on the game board
void Board::handleCollision()
{
	std::erase_if(m_static_objects, [](const auto& static_object) {return static_object->getDelete(); });
	//Cancellation of change in gravity
	if (m_player->isGravityChange())
	{
		m_gravity = -m_gravity;
		m_world.SetGravity(m_gravity);
	}
	//If the player is disqualified
	if (!m_player->isAlive())
	{
		m_player->setRegularState();
		m_player->resetPlayerAfterKill();
	}
	//setr eguler
	if (m_player->isRegularState())
	{
		m_player->setRegularState();
	}
	//Changing the color of the gate
	for (auto& object : m_static_objects)
	{
		if (typeid(*object) == typeid(Entrance))
		{
			auto entrance = static_cast<Entrance*>(object.get());
			entrance->update();  
		}
	}
	//Checking the status of the player and updating his state
	if (m_player->isSpeedState())	/*so*/ m_player->setSpeedState();
	if (m_player->isShieldState()) /*so*/  m_player->setShieldState();
	if (m_player->isFlystate())   /*so*/   m_player->setFlyState();
	//Time measurement for shield and speed
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
		//update the object direction
		object->update();
	}
}

//This function creates the board according to the level map
void Board::createLevel(const GameMaps level, const GameBackground back)
{
	m_background.setTexture(Resources::instance().getGameBackground(back));
	m_background.setScale(1.f, 1.f); 
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

//This function creates the different objects on the board using the colors we defined for each object
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
	//creating the other objects on the board
	else
	{
		//using the Factory create the moving objects
		auto movingObject = Factory<MovingObject>::createObject(m_source.getPixel(x, y), m_world, location);
		if (movingObject)
		{
			addMovingObject(std::move(movingObject));
		}
		else
		{
			//using the Factory create the static objects 
			auto staticObject = Factory<StaticObject>::createObject(m_source.getPixel(x, y), m_world, location);
			if (staticObject)
			{
				addStaticObject(std::move(staticObject));
			}
		}
	}
}

//This function adds the moving objects to the moving vector
void Board::addMovingObject(std::unique_ptr<MovingObject> object)
{
	m_moving_objects.push_back(std::move(object));
}

//This function adds the static objects to the static vector
void Board::addStaticObject(std::unique_ptr<StaticObject> object)
{
	m_static_objects.push_back(std::move(object));
}

//This function returns the position of the player on the board
const b2Vec2 Board::getPlayerPosition()const
{
	return m_player->getPosition();
}

//This functionmoving the game background
void Board::viewBackground(const float addition)
{
	m_background.setPosition(m_background.getPosition().x + addition, m_background.getPosition().y);
}