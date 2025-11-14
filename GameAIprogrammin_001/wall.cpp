#include "wall.h"

Wall::Wall()
{
	positionS = Vector2{ 0, 0 };
	angle = Vector2{ 10, 0 };
	positionE = positionS + angle;
}

void Wall::Draw(Color color)
{
	DrawLine(positionS.x, positionS.y, positionE.x, positionE.y, color);
}

Vector2 Wall::GetStart()
{
	return positionS;
}

Vector2 Wall::GetEnd()
{
	return positionE;
}

Vector2 Wall::GetVector()
{
	return angle;
}
