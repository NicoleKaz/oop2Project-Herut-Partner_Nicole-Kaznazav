#include "GdContactListener.h"


void handleCollision(GameObject& object1, GameObject& object2);
//===========================================================

void handlePlayerFloor(GameObject& player, GameObject& floor) 
{
    static_cast<Player&>(player).setTouchingFloor(true);
}

void handleFloorPlayer(GameObject& floor, GameObject& player)
{
    handlePlayerFloor(player, floor);
}

//===========================================================

void handlePlayerCoin(GameObject& player, GameObject& coin) 
{
    auto& coinObj = static_cast<Coin&>(coin);
    switch (coinObj.getType()) 
    {
    case CoinScore:
        coinObj.setDelete();
        static_cast<Player&>(player).increasePoints();
        break;
    case CoinSpeed:
        static_cast<Player&>(player).beSpeed();
        break;
    case CoinShield:
        static_cast<Player&>(player).beShield();
        break;
    case CoinFly:
        static_cast<Player&>(player).beFly();
        break;
    }
}

void handleCoinPlayer(GameObject& coin, GameObject& player)
{
    handlePlayerCoin(player, coin);
}

//===========================================================

void handlePlayerThorn(GameObject& player, GameObject& thorn) 
{
    static_cast<Player&>(player).setPlayerKill();
}

void handleThornPlayer(GameObject& thorn, GameObject& player)
{
    handlePlayerThorn(player, thorn);
}

//===========================================================

void handlePlayerWheelSpike(GameObject& player, GameObject& wheel) 
{
    static_cast<Player&>(player).setPlayerKill();
}

void handleWheelSpikePlayer(GameObject& wheel, GameObject& player)
{
    handlePlayerWheelSpike(player, wheel);
}

//===========================================================

void handlePlayerEntrance(GameObject& player, GameObject& entrance) 
{
    auto& entranceObj = static_cast<Entrance&>(entrance);
    switch (entranceObj.getType()) 
    {
    case GateGravityChange:
        static_cast<Player&>(player).reverseGravity();
        entranceObj.changeColorTemporarily(sf::Color::Red);
        break;
    case GateNoFly:
        static_cast<Player&>(player).setRegular();
        entranceObj.changeColorTemporarily(sf::Color::Blue);
        break;
    case GateLevelEnd:
        static_cast<Player&>(player).setWin();
        entranceObj.changeColorTemporarily(sf::Color::Green);
        break;
    }
}

void handleEntrancePlayer(GameObject& entrance, GameObject& player)
{
    handlePlayerEntrance(player, entrance);
}

//===========================================================

void handlePlayerJumper(GameObject& player, GameObject& jumper) 
{
    auto& jumperObj = static_cast<Jumper&>(jumper);
    switch (jumperObj.getType()) 
    {
    case Jumper1:
        static_cast<Player&>(player).chooseAndJump(45.f);
        break;
    case Jumper2:
        static_cast<Player&>(player).chooseAndJump(55.f);
        break;
    }
}

void handleJumperPlayer(GameObject& jumper, GameObject& player)
{
    handlePlayerJumper(player, jumper);
}

//===========================================================

void handlePlayerChaserEnemy(GameObject& player, GameObject& chaser) 
{
    static_cast<Player&>(player).setPlayerKill();
}

void handleChaserEnemyPlayer(GameObject& chaser, GameObject& player)
{
    handlePlayerChaserEnemy(player, chaser);
}

//===========================================================

void handleChaserEnemyThorn(GameObject& chaser, GameObject& thorn)
{
    static_cast<ChaserEnemy&>(chaser).notifyCollision();
}

void handleThornChaserEnemy(GameObject& thorn, GameObject& chaser)
{
    handleChaserEnemyThorn(chaser, thorn);
}

//===========================================================

void handleChaserEnemyChaserEnemy(GameObject& chaser1, GameObject& chaser2) 
{
    static_cast<ChaserEnemy&>(chaser1).notifyCollision();
    static_cast<ChaserEnemy&>(chaser2).notifyCollision();
}

//===========================================================

void handlePlayerShooterEnemy(GameObject& player, GameObject& shooter)
{
    static_cast<Player&>(player).setPlayerKill();
}

void handleShooterEnemyPlayer(GameObject& shooter, GameObject& player)
{
    handlePlayerShooterEnemy(player, shooter);
}

//===========================================================

void handlePlayerBullet(GameObject& player, GameObject& bullet)
{
    static_cast<Player&>(player).setPlayerKill();
}

void handleBulletPlayer(GameObject& bullet, GameObject& player)
{
    handlePlayerShooterEnemy(player, bullet);
}

//===========================================================

using HitFunctionPtr = std::function<void(GameObject&, GameObject&)>;
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

//The Collision map
HitMap initializeCollisionMap() {
    HitMap phm;
    phm[Key(typeid(Player), typeid(Floor))] = &handlePlayerFloor;
    phm[Key(typeid(Floor), typeid(Player))] = &handleFloorPlayer;

    phm[Key(typeid(Player), typeid(Coin))] = &handlePlayerCoin;
    phm[Key(typeid(Coin), typeid(Player))] = &handleCoinPlayer;

    phm[Key(typeid(Player), typeid(Thorn))] = &handlePlayerThorn;
    phm[Key(typeid(Thorn), typeid(Player))] = &handleThornPlayer;

    phm[Key(typeid(Player), typeid(WheelSpike))] = &handlePlayerWheelSpike;
    phm[Key(typeid(WheelSpike), typeid(Player))] = &handleWheelSpikePlayer;

    phm[Key(typeid(Player), typeid(Entrance))] = &handlePlayerEntrance;
    phm[Key(typeid(Entrance), typeid(Player))] = &handleEntrancePlayer;

    phm[Key(typeid(Player), typeid(Jumper))] = &handlePlayerJumper;
    phm[Key(typeid(Jumper), typeid(Player))] = &handleJumperPlayer;

    phm[Key(typeid(Player), typeid(ChaserEnemy))] = &handlePlayerChaserEnemy;
    phm[Key(typeid(ChaserEnemy), typeid(Player))] = &handleChaserEnemyPlayer;

    phm[Key(typeid(ChaserEnemy), typeid(Thorn))] = &handleChaserEnemyThorn;
    phm[Key(typeid(Thorn), typeid(ChaserEnemy))] = &handleThornChaserEnemy;

    phm[Key(typeid(ChaserEnemy), typeid(ChaserEnemy))] = &handleChaserEnemyChaserEnemy;

    phm[Key(typeid(Player), typeid(ShooterEnemy))] = &handlePlayerShooterEnemy;
    phm[Key(typeid(ShooterEnemy), typeid(Player))] = &handleShooterEnemyPlayer;

    phm[Key(typeid(Player), typeid(Bullet))] = &handlePlayerBullet;
    phm[Key(typeid(Bullet), typeid(Player))] = &handleBulletPlayer;

    return phm;
}

//This function retrieves a function pointer (HitFunctionPtr) for handling collisions between two types, 
//based on a pre-defined collision map
HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2) 
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end()) 
    {
        return nullptr;
    }
    return mapEntry->second;
}

//This function is responsible for handling collisions between two GameObject
void handleCollision(GameObject& object1, GameObject& object2)
{
    auto collisionFunc = lookup(typeid(object1), typeid(object2));
    if (collisionFunc) 
    {
        collisionFunc(object1, object2);
    }
}

//callback function for the Box2D physics engine that gets called whenever two fixtures begin to make contact
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
        handleCollision(*objectA, *objectB);
    }
}
