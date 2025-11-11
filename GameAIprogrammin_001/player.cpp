#include "player.h"

void Player::Update()
{
    if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
    {
        velocity.x = 3;
    }
    else if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
    {
        velocity.x = -3;
    }
    else
    {
        velocity.x = 0;
    }

    if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN))
    {
        velocity.y = -3;
    }
    else if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP))
    {
        velocity.y = 3;
    }
    else
    {
        velocity.y = 0;
    }

    position += velocity;
}

void Player::Draw(Color color)
{
    DrawCircle(position.x, position.y, 20, color);
}

Vector2 Player::GetPosition()
{
    return position;
}

Vector2 Player::GetVelocity()
{
    return velocity;
}
