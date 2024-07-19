#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>
#include <functional>
#include <typeindex>
#include <iostream>
#include <typeinfo>
#include <string>
#include <map>
#include "ShieldPlayerState.h"
#include "SpeedPlayerState.h"
#include "FLYPlayerState.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "ShooterEnemy.h"
#include "ChaserEnemy.h"
#include "GameObject.h"
#include "WheelSpike.h"
#include "Resources.h"
#include "Entrance.h"
#include "Jumper.h"
#include "Player.h"
#include "Bullet.h"
#include "Floor.h"
#include "Thorn.h"
#include "Enemy.h"
#include "Coin.h"


class GdContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact) override;
};
