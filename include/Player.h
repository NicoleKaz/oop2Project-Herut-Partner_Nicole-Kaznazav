#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h"
#include "MovingObject.h"
#include "PlayerState.h"
#include "regularPlayerState.h"
#include "SpeedPlayerState.h"
#include "ShieldPlayerState.h"
#include "FlyPlayerState.h"

class Player : public MovingObject
{
public:
    void setTouchingFloor(bool);
    Player(b2World&, const std::vector<GameTextures>, const sf::Vector2f);
    void move();
    void updateDirection()override;
    void increasePoints();
    void resetPlayerAfterKill();
    void releaseRight();
    void releaseLeft();
    void releaseSpace();
    void hop(const float) const;
    void reverseGravity();
    void updateTools(sf::Sprite& background);
    const bool isGravityChange();
    void increaseSpeed();
    bool isSpeedState() const ;
    bool isShieldState() const;
    bool isFlystate() const;
    void beShield();

    void beRegular();

    void beFly();

    void setGravity();

    void setShieldState();
    void setFlyState();
    void setSpeedState();
    void setRegularState();
    b2Vec2 getPosition() const;
    void setWin();
    const bool isWinner() const;

    void chooseAndJump(const float jump);

    void setPlayerKill();
    const bool isAlive()const;

    const int getCoins()const;

private:
    bool m_direction[4] = { false, false, false, false };

    std::unique_ptr <PlayerState> m_state;
    std::vector<GameTextures> m_player_textures;
    int m_coins;
    bool m_beSpeed = false;
    bool m_beShield = false;
	bool m_beFly = false;

    b2Vec2 m_first_location;
    b2Vec2 m_gravity;


    bool m_win = false;
    bool m_alive = true;
    bool m_state_change = false;
    bool m_gravity_changed = false;



    void changeBodyAndSprite(const GameTextures);
    b2Body* m_body; // נניח ש-player משתמש ב-Box2D לתנועות פיזיקליות
    sf::Sprite m_sprite;
	bool m_touchingFloor = false;
    sf::Clock m_speedClock; // טיימר עבור מצב מהירות
    sf::Clock m_shieldClock; // טיימר עבור מצב מגן



};
