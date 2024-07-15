// d2ContactListener.cpp
#include "GdContactListener.h"


// îéîåù äôåð÷öéåú ùì äîçì÷ä d2ContactListener
void GdContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    GameObject* objectA = reinterpret_cast<GameObject*>(bodyA->GetUserData().pointer);
    GameObject* objectB = reinterpret_cast<GameObject*>(bodyB->GetUserData().pointer);


    if (objectA && objectB)
    {
        auto& player = (typeid(*objectA) == typeid(Player)) ? *objectA : *objectB;
        auto& other = (typeid(*objectA) == typeid(Player)) ? *objectB : *objectA;

        if (typeid(player) == typeid(Player) && typeid(other) == typeid(Floor))
        {
            static_cast<Player&>(player).setTouchingFloor(true);
        }
        if (typeid(player) == typeid(Player) && typeid(other) == typeid(Coin))
        {
            //static_cast<Coin&>(other).setDelete();
            auto& coin = static_cast<Coin&>(other);
            switch (coin.getType())
            {
            case CoinScore:
                static_cast<Coin&>(other).setDelete();
                static_cast<Player&>(player).increasePoints();
                break;
            case CoinSpeed:
                static_cast<Player&>(player).increaseSpeed();
                break;
            case CoinShield:
                static_cast<Player&>(player).beShield();
                break;
            case CoinFly:
                static_cast<Player&>(player).beFly();
                break;
            }
        }
        if (typeid(player) == typeid(Player) && typeid(other) == typeid(Thorn))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        if (typeid(player) == typeid(Player) && typeid(other) == typeid(WheelSpike))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        if (typeid(player) == typeid(Player) && typeid(other) == typeid(Entrance))
        {
            auto& entrance = static_cast<Entrance&>(other);
            switch (entrance.getType())
            {
            case GateGravityChange:
                static_cast<Player&>(player).reverseGravity();
                entrance.changeColorTemporarily(sf::Color::Red);
                break;
            case GateNoFly:
                static_cast<Player&>(player).setRegular();
                entrance.changeColorTemporarily(sf::Color::Blue);
                break;
            case GateLevelEnd:
                static_cast<Player&>(player).setWin();
                entrance.changeColorTemporarily(sf::Color::Green);
                break;
            }
        }

        if (typeid(player) == typeid(Player) && typeid(other) == typeid(Jumper))
        {
            auto& jumper = static_cast<Jumper&>(other);
            switch (jumper.getType())
            {
            case Jumper1:
                static_cast<Player&>(player).chooseAndJump(45.f);
                break;
            case Jumper2:
                static_cast<Player&>(player).chooseAndJump(55.f);
                break;
            }
        }

        if ((typeid(*objectA) == typeid(ShooterEnemy) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(ShooterEnemy) && typeid(*objectA) == typeid(Player)))
        {
            std::cout << "Player hit by ShooterEnemy" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }

        if ((typeid(*objectA) == typeid(Bullet) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(Bullet) && typeid(*objectA) == typeid(Player)))
        {

            std::cout << "Player hit by Bullet" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }

        // èéôåì áäúðâùåéåú ùì ChaserEnemy
        if ((typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(ChaserEnemy) && typeid(*objectA) == typeid(Player)))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        if (typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) != typeid(Player) && typeid(*objectB) != typeid(Floor))
        {
            static_cast<ChaserEnemy&>(*objectA).notifyCollision();
        }
        if (typeid(*objectB) == typeid(ChaserEnemy) && typeid(*objectA) != typeid(Player) && typeid(*objectA) != typeid(Floor))
        {
            static_cast<ChaserEnemy&>(*objectB).notifyCollision();
        }
        if (typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) == typeid(ChaserEnemy))
        {
            static_cast<ChaserEnemy&>(*objectA).notifyCollision();
            static_cast<ChaserEnemy&>(*objectB).notifyCollision();
        }
    }
}