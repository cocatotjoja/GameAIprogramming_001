#pragma once
#include "raylib.h"

class Agent
{
private:
	Vector2 position;
	Vector2 velocity;
	int state;

	Vector2 Seek(Vector2 target);
	Vector2 Flee(Vector2 target);
	Vector2 Pursue(Vector2 target);
	Vector2 Evade(Vector2 target);
	Vector2 Arrive(Vector2 target);
	Vector2 Wander(Vector2 target);

public:
	void Update(Vector2 target);
	void Draw(Color color);

};
