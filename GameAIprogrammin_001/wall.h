#pragma once
#include "raylib.h"
#include "raymath.h"

class Wall
{
private:
	Vector2 positionS;
	Vector2 positionE;
	Vector2 angle;
public:
	Wall();
	Wall(Vector2 position, Vector2 wallAngle) : positionS(position), angle(wallAngle), positionE(positionS + wallAngle) {};
	void Draw(Color color);
};
