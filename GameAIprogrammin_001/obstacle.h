#pragma once
#include "raylib.h"
#include "raymath.h"

class Obstacle
{
private:
	Vector2 position;
	float radius;
public:
	Obstacle();
	Obstacle(Vector2 position, float radius) : position(position), radius(radius) {};
	void Draw(Color color);
	Vector2 GetPosition();
	float GetRadius();
};
