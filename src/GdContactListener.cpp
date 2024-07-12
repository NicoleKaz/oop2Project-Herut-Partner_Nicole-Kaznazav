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
        else if (typeid(player) == typeid(Player) && typeid(other) == typeid(Coin))
        {
            static_cast<Coin&>(other).setDelete();
            auto& coin = static_cast<Coin&>(other);
            switch (coin.getType())
            {
            case CoinSpeed:
                static_cast<Player&>(player).increaseSpeed();
                break;
            case CoinScore:
                static_cast<Player&>(player).increasePoints();
                break;
            case CoinShield:
                static_cast<Player&>(player).beShield();
                break;
            case CoinFly:
                static_cast<Player&>(player).beFly();
                break;
            }
        }
        else if (typeid(player) == typeid(Player) && typeid(other) == typeid(Thorn))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        else if (typeid(player) == typeid(Player) && typeid(other) == typeid(WheelSpike))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        else if (typeid(player) == typeid(Player) && typeid(other) == typeid(Entrance))
        {
            auto& entrance = static_cast<Entrance&>(other);
            switch (entrance.getType())
            {
            case Gate3:
                static_cast<Player&>(player).reverseGravity();
                static_cast<Entrance&>(other).changeColorTemporarily(sf::Color::Red);
                break;
            case Gate2:
                static_cast<Player&>(player).beRegular();
                break;
            case Gate5:
                static_cast<Player&>(player).setWin();
                break;
            }
        }
        else if (typeid(player) == typeid(Player) && typeid(other) == typeid(Jumper))
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

        /* else if (typeid(player) == typeid(Player) && typeid(other) == typeid(ShooterEnemy))
         {
             static_cast<Player&>(player).setPlayerKill();
         }
         else if (typeid(player) == typeid(Player) && typeid(other) == typeid(Bullet))
         {
             static_cast<Player&>(player).setPlayerKill();
         }
         */

        else if ((typeid(*objectA) == typeid(ShooterEnemy) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(ShooterEnemy) && typeid(*objectA) == typeid(Player)))
        {
            std::cout << "Player hit by ShooterEnemy" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }

        else if ((typeid(*objectA) == typeid(Bullet) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(Bullet) && typeid(*objectA) == typeid(Player)))
        {

            std::cout << "Player hit by Bullet" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }


        //if ((typeid(*objectA) == typeid(Bullet) && typeid(*objectB) == typeid(Player)) ||
        //    (typeid(*objectB) == typeid(Bullet) && typeid(*objectA) == typeid(Player)))
        //{
        //    std::cout << "Player hit by Bullet" << std::endl;
        //    //static_cast<Player&>(player).setPlayerKill();
        //    // Determine which object is the player and cast it
        //    if (typeid(*objectA) == typeid(Player))
        //    {
        //        static_cast<Player&>(*objectA).setPlayerKill();
        //    }
        //    else
        //    {
        //        static_cast<Player&>(*objectB).setPlayerKill();
        //    }
        //}



        /*if (typeid(player) == typeid(Player))
        {
            if (typeid(other) == typeid(Bullet))
            {
                std::cout << "Player hit by Bullet" << std::endl;
                static_cast<Player&>(player).setPlayerKill();
            }
            else if (typeid(other) == typeid(ShooterEnemy))
            {
                std::cout << "Player hit by ShooterEnemy" << std::endl;
                static_cast<Player&>(player).setPlayerKill();
            }
        }*/



        // èéôåì áäúðâùåéåú ùì ChaserEnemy
        else if ((typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(ChaserEnemy) && typeid(*objectA) == typeid(Player)))
        {
            static_cast<Player&>(player).setPlayerKill();
        }
        else if (typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) != typeid(Player) && typeid(*objectB) != typeid(Floor))
        {
            static_cast<ChaserEnemy&>(*objectA).notifyCollision();
        }
        else if (typeid(*objectB) == typeid(ChaserEnemy) && typeid(*objectA) != typeid(Player) && typeid(*objectA) != typeid(Floor))
        {
            static_cast<ChaserEnemy&>(*objectB).notifyCollision();
        }
        else if (typeid(*objectA) == typeid(ChaserEnemy) && typeid(*objectB) == typeid(ChaserEnemy))
        {
            static_cast<ChaserEnemy&>(*objectA).notifyCollision();
            static_cast<ChaserEnemy&>(*objectB).notifyCollision();
        }


        // èéôåì áäúðâùåéåú ùì ShooterEnemy with ChaserEnemy
        /*if (typeid(*objectA) == typeid(ShooterEnemy) && typeid(*objectB) == typeid(ChaserEnemy))
        {
            static_cast<ShooterEnemy&>(*objectA).notifyCollision();
            static_cast<ChaserEnemy&>(*objectB).notifyCollision();
        }
        else if (typeid(*objectB) == typeid(ShooterEnemy) && typeid(*objectA) == typeid(ChaserEnemy))
        {
            static_cast<ShooterEnemy&>(*objectB).notifyCollision();
            static_cast<ChaserEnemy&>(*objectA).notifyCollision();
        }*/
    }
}