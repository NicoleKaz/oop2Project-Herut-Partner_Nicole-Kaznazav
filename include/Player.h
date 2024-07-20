#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "regularPlayerState.h"
#include "ShieldPlayerState.h"
#include "SpeedPlayerState.h"
#include "FlyPlayerState.h"
#include "MovingObject.h"
#include "PlayerState.h"
#include "Resources.h"


class Player : public MovingObject
{
public:
    Player(b2World&, const std::vector<GameTextures>, const sf::Vector2f);
    b2Vec2 getPosition() const;
    void setTouchingFloor(bool);
    void move();
    void updateDirection()override;
    void increasePoints();
    void resetPlayerAfterKill();
    void releaseRight();
    void releaseLeft();
    void releaseSpace();
    void hop(const float) const;
    void reverseGravity();
    void setRegular();
    void beShield();
    void beRegular();
    void beFly();
    void beSpeed();
    void setGravity();
    void setShieldState();
    void setFlyState();
    void setSpeedState();
    void setRegularState();
    void updateTools(sf::Sprite& background);
    void setWin();
    void chooseAndJump(const float jump);
    void setPlayerKill();
    const bool isGravityChange();
    const bool isWinner() const;
    const bool isAlive()const;
    bool isSpeedState() const ;
    bool isShieldState() const;
    bool isFlystate() const;
    bool isRegularState() const;
    const int getCoins()const;

private:
    b2Body* m_body; 
    sf::Sprite m_sprite;
    std::unique_ptr <PlayerState> m_state;
    std::vector<GameTextures> m_player_textures;
    b2Vec2 m_first_location;
    b2Vec2 m_gravity;
    bool m_touchingFloor = false;
    bool m_beSpeed = false;
    bool m_beShield = false;
    bool m_beFly = false;
    bool m_win = false;
    bool m_alive = true;
    bool m_state_change = false;
    bool m_gravity_changed = false;
    bool m_direction[4] = { false, false, false, false };
    void changeBodyAndSprite(const GameTextures);
    int m_coins;
    sf::Clock m_speedClock;
    sf::Clock m_shieldClock;
};
