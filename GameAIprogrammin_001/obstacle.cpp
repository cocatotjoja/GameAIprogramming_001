#include "obstacle.h"

Obstacle::Obstacle()
{
	position = { 0,0 };
	radius = 15;
}

void Obstacle::Draw(Color color)
{
	DrawCircle(position.x, position.y, radius, color);
}

Vector2 Obstacle::GetPosition()
{
	return position;
}

float Obstacle::GetRadius()
{
	return radius;
}