#include "RegularPlayerState.h"


void RegularPlayerState::move(bool* direction, b2Body* body, bool& m_touchingFloor, const b2Vec2 gravity, sf::Sprite& object)
{
    if (direction[Up])
    {
        if (m_touchingFloor)
        {
            //to avoid "icetower" jumps (reset vilocity)
            body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));

            //jump up/down acording to the gravity
            if (gravity.y > 0)
                body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -REGULER_JUMP_FORCE), true);
            else
                body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, REGULER_JUMP_FORCE), true);

            //reset sensors
            m_touchingFloor = false;
        }
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
    if (direction[Stay])
    {
        float currentSpeed_y = body->GetLinearVelocity().y;
        body->SetLinearVelocity({ 0, currentSpeed_y });
    }

    //move and rotate the sprite acording to the body
    object.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
    object.setRotation(body->GetAngle() * 180 / b2_pi);

}




//void RegularPlayerState::collideBrick(bool& touching_ground, bool& alive)
//{
//	std::cout << "CollideBrick" << std::endl;
//    touching_ground = true;
//}

