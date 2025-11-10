#pragma once
#include "raylib.h"

class Player
{
private:
	Vector2 position{400, 400};
public:
	void Update();
	void Draw(Color color);
};
