#pragma once
#include "raylib.h"
#include "raymath.h"

class Player
{
private:
	Vector2 position{400, 400};
	Vector2 velocity{ 0, 0 };
public:
	void Update();
	void Draw(Color color);
	Vector2 GetPosition();
	Vector2 GetVelocity();
};
