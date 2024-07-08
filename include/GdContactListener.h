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

#include "ShieldPlayerState.h"
#include "SpeedPlayerState.h"
#include "FLYPlayerState.h"

#include <functional>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

class GdContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact) override;
};
