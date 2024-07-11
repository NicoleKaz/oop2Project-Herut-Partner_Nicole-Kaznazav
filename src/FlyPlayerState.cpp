#include "FlyPlayerState.h"

void FlyPlayerState::move(bool* direction, b2Body* body, bool& m_touchingFloor, const b2Vec2 gravity, sf::Sprite& object)
{
    if (direction[Up])
    {

        //saving last vilocity and keep moving that way
        float currentSpeed_y = body->GetLinearVelocity().y;

        body->SetLinearVelocity({ PLAYER_MOVEMENT_SPEED, currentSpeed_y });

        //jump up/down acording to the gravity
        if (gravity.y > 0)
            body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -FLY_FORCE), true);
        else
            body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, FLY_FORCE), true);
    }
    if (direction[Right])
    {
        //keep Y vilocity
        float currentSpeed_y = body->GetLinearVelocity().y;
        //move X acording to player movement
        body->SetLinearVelocity({ PLAYER_MOVEMENT_SPEED, currentSpeed_y });
    }
    if (direction[Left])
    {
        float currentSpeed_y = body->GetLinearVelocity().y;
        body->SetLinearVelocity({ -PLAYER_MOVEMENT_SPEED, currentSpeed_y });
    }
    else
    {
        //saving last vilocity and keep moving that way
        float currentSpeed_y = body->GetLinearVelocity().y;

        body->SetLinearVelocity({ PLAYER_MOVEMENT_SPEED, currentSpeed_y });
    }

    //move the sprite
    object.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
}





//void FlyPlayerState::collideBrick(bool& touching_ground, bool& alive)
//{
//	std::cout << "CollideBrick" << std::endl;
//    touching_ground = true;
//}

