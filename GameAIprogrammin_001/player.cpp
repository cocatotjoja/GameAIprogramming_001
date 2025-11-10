#include "player.h"

void Player::Update()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        position.x += 3;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        position.x -= 3;
    }
    else if (IsKeyDown(KEY_UP))
    {
        position.y -= 3;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        position.y += 3;
    }
}

void Player::Draw(Color color)
{
    DrawCircle(position.x, position.y, 20, color);
}
