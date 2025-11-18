#include "wall.h"

Wall::Wall()
{
	positionS = Vector2{ 0, 0 };
	angle = Vector2{ 10, 0 };
	positionE = positionS + angle;
}

Wall::Wall(float width, float height, float margin)
{
	positionS = Vector2{ (float)GetRandomValue(margin, width - margin), (float)GetRandomValue(margin, height - margin) };
	positionE = Vector2{ (float)GetRandomValue(margin, width - margin), (float)GetRandomValue(margin, height - margin) };
	angle = positionE - positionS;

	// Limit length
	if (Vector2Length(angle) > 500)
	{
		angle = Vector2Normalize(angle) * 500;
		positionE = positionS + angle;
	}
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
