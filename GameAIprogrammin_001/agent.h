#pragma once
#include <iostream>
#include "raylib.h"
#include "raymath.h"

class Agent
{
private:
	Vector2 position;
	Vector2 velocity;
	Vector2 chase;
	float maxSpeed;
	int state;

	Vector2 Seek(Vector2 targetPos);
	Vector2 Flee(Vector2 targetPos);
	Vector2 Pursue(Vector2 targetPos, Vector2 targetVel);
	Vector2 Evade(Vector2 targetPos, Vector2 targetVel);
	Vector2 Arrive(Vector2 targetPos);
	Vector2 Wander(Vector2 targetPos);

public:
	Agent(Vector2 position, Vector2 velocity) : position(position), velocity(velocity), chase(Vector2{ 0 , 0 }), maxSpeed(100), state(1) {};
	//~Agent();
	void CheckState();
	void Update(Vector2 target, Vector2 targetVel);
	void Draw(Color color);

};
