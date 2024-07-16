#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "GameObject.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "Floor.h"
#include "Coin.h"
#include "Thorn.h"
#include "WheelSpike.h"
#include "Entrance.h"
#include "Jumper.h"
#include "Enemy.h"
#include "ChaserEnemy.h"
#include "ShooterEnemy.h"
#include "Bullet.h"
#include <functional>
#include <iostream>
#include <map>
#include <typeindex>
#include "ShieldPlayerState.h"
#include "SpeedPlayerState.h"
#include "FLYPlayerState.h"
#include <string>
#include <typeinfo>

class GdContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact) override;
};
