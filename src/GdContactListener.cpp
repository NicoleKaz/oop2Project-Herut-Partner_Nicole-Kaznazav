﻿#include "GdContactListener.h"


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
        else if ((typeid(*objectA) == typeid(ShooterEnemy) && typeid(*objectB) == typeid(Player)) ||
            (typeid(*objectB) == typeid(ShooterEnemy) && typeid(*objectA) == typeid(Player)))
        {
            std::cout << "Player hit by ShooterEnemy" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }

        
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
        else if  ((typeid(*objectA) == typeid(Player) || typeid(*objectB) == typeid(Player)))
        {
            std::cout << "Player hit by Bullet" << std::endl;
            static_cast<Player&>(player).setPlayerKill();
        }
    }
}
//
//#include "GdContactListener.h"
////#include <iostream>
////#include <functional>
////#include <map>
////#include <typeinfo>
////#include <typeindex>
////
////#include "GameObject.h"
////#include "Player.h"
////#include "Floor.h"
////#include "Coin.h"
////#include "Thorn.h"
////#include "WheelSpike.h"
////#include "Entrance.h"
////#include "Jumper.h"
////#include "ShooterEnemy.h"
////#include "ChaserEnemy.h"
//
//// פונקציות התנגשות
//
//void handlePlayerFloor(GameObject& player, GameObject&) {
//    static_cast<Player&>(player).setTouchingFloor(true);
//}
//
//void handlePlayerCoin(GameObject& player, GameObject& coin) {
//    auto& coinObj = static_cast<Coin&>(coin);
//    switch (coinObj.getType()) {
//    case CoinScore:
//        coinObj.setDelete();
//        static_cast<Player&>(player).increasePoints();
//        break;
//    case CoinSpeed:
//        static_cast<Player&>(player).increaseSpeed();
//        break;
//    case CoinShield:
//        static_cast<Player&>(player).beShield();
//        break;
//    case CoinFly:
//        static_cast<Player&>(player).beFly();
//        break;
//    }
//}
//
//void handlePlayerThorn(GameObject& player, GameObject&) {
//    static_cast<Player&>(player).setPlayerKill();
//}
//
//void handlePlayerWheelSpike(GameObject& player, GameObject&) {
//    static_cast<Player&>(player).setPlayerKill();
//}
//
//void handlePlayerEntrance(GameObject& player, GameObject& entrance) {
//    auto& entranceObj = static_cast<Entrance&>(entrance);
//    switch (entranceObj.getType()) {
//    case GateGravityChange:
//        static_cast<Player&>(player).reverseGravity();
//        entranceObj.changeColorTemporarily(sf::Color::Red);
//        break;
//    case GateNoFly:
//        static_cast<Player&>(player).setRegular();
//        entranceObj.changeColorTemporarily(sf::Color::Blue);
//        break;
//    case GateLevelEnd:
//        static_cast<Player&>(player).setWin();
//        entranceObj.changeColorTemporarily(sf::Color::Green);
//        break;
//    }
//}
//
//void handlePlayerJumper(GameObject& player, GameObject& jumper) {
//    auto& jumperObj = static_cast<Jumper&>(jumper);
//    switch (jumperObj.getType()) {
//    case Jumper1:
//        static_cast<Player&>(player).chooseAndJump(45.f);
//        break;
//    case Jumper2:
//        static_cast<Player&>(player).chooseAndJump(55.f);
//        break;
//    }
//}
//
//void handlePlayerShooterEnemy(GameObject& player, GameObject&) {
//    std::cout << "Player hit by ShooterEnemy" << std::endl;
//    static_cast<Player&>(player).setPlayerKill();
//}
//
//void handlePlayerChaserEnemy(GameObject& player, GameObject&) {
//    static_cast<Player&>(player).setPlayerKill();
//}
//
//void handleChaserEnemyCollision(GameObject& chaser, GameObject& other) {
//    std::cout << "ChaserEnemy collision with " << typeid(other).name() << std::endl;
//    if (typeid(other) != typeid(Player) && typeid(other) != typeid(Floor)) {
//        static_cast<ChaserEnemy&>(chaser).notifyCollision();
//    }
//}
//
//void handleChaserEnemyChaserEnemy(GameObject& chaser1, GameObject& chaser2) {
//    static_cast<ChaserEnemy&>(chaser1).notifyCollision();
//    static_cast<ChaserEnemy&>(chaser2).notifyCollision();
//}
//
//using HitFunctionPtr = std::function<void(GameObject&, GameObject&)>;
//using Key = std::pair<std::type_index, std::type_index>;
//using HitMap = std::map<Key, HitFunctionPtr>;
//
//HitMap initializeCollisionMap() {
//    HitMap phm;
//    phm[Key(typeid(Player), typeid(Floor))] = &handlePlayerFloor;
//    phm[Key(typeid(Floor), typeid(Player))] = &handlePlayerFloor;
//    phm[Key(typeid(Player), typeid(Coin))] = &handlePlayerCoin;
//    phm[Key(typeid(Coin), typeid(Player))] = &handlePlayerCoin;
//    phm[Key(typeid(Player), typeid(Thorn))] = &handlePlayerThorn;
//    phm[Key(typeid(Thorn), typeid(Player))] = &handlePlayerThorn;
//    phm[Key(typeid(Player), typeid(WheelSpike))] = &handlePlayerWheelSpike;
//    phm[Key(typeid(WheelSpike), typeid(Player))] = &handlePlayerWheelSpike;
//    phm[Key(typeid(Player), typeid(Entrance))] = &handlePlayerEntrance;
//    phm[Key(typeid(Entrance), typeid(Player))] = &handlePlayerEntrance;
//    phm[Key(typeid(Player), typeid(Jumper))] = &handlePlayerJumper;
//    phm[Key(typeid(Jumper), typeid(Player))] = &handlePlayerJumper;
//    phm[Key(typeid(ChaserEnemy), typeid(Thorn))] = &handleChaserEnemyCollision;
//    phm[Key(typeid(Thorn), typeid(ChaserEnemy))] = &handleChaserEnemyCollision;
//    phm[Key(typeid(Player), typeid(ChaserEnemy))] = &handlePlayerChaserEnemy;
//    phm[Key(typeid(ChaserEnemy), typeid(Player))] = &handlePlayerChaserEnemy;
//    phm[Key(typeid(Player), typeid(ShooterEnemy))] = &handlePlayerShooterEnemy;
//    phm[Key(typeid(ShooterEnemy), typeid(Player))] = &handlePlayerShooterEnemy;
//    phm[Key(typeid(ChaserEnemy), typeid(ChaserEnemy))] = &handleChaserEnemyChaserEnemy;
//    return phm;
//}
//
//
//HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2) {
//    static HitMap collisionMap = initializeCollisionMap();
//    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
//    if (mapEntry == collisionMap.end()) {
//        return nullptr;
//    }
//    return mapEntry->second;
//}
//
//void handleCollision(GameObject& object1, GameObject& object2)
//{
//    auto collisionFunc = lookup(typeid(object1), typeid(object2));
//    if (collisionFunc) 
//    {
//        collisionFunc(object1, object2);
//    }
//}
//
//void GdContactListener::BeginContact(b2Contact* contact) {
//    b2Fixture* fixtureA = contact->GetFixtureA();
//    b2Fixture* fixtureB = contact->GetFixtureB();
//    b2Body* bodyA = fixtureA->GetBody();
//    b2Body* bodyB = fixtureB->GetBody();
//
//    GameObject* objectA = reinterpret_cast<GameObject*>(bodyA->GetUserData().pointer);
//    GameObject* objectB = reinterpret_cast<GameObject*>(bodyB->GetUserData().pointer);
//
//    if (objectA && objectB) {
//        handleCollision(*objectA, *objectB);
//    }
//}
