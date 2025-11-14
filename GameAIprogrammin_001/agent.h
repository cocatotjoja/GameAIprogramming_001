#pragma once
#include <iostream>
#include <array>
#include "raylib.h"
#include "raymath.h"
#include "wall.h"

class Agent
{
private:
	Vector2 position;
	Vector2 velocity;
	float maxAcceleration;
	float wanderAngle;
	Vector2 chase;
	Color color = { 176, 190, 162, 255 };
	float maxSpeed;
	int state;

	Vector2 Seek(Vector2 targetPos);
	Vector2 Flee(Vector2 targetPos);
	Vector2 Pursue(Vector2 targetPos, Vector2 targetVel);
	Vector2 Evade(Vector2 targetPos, Vector2 targetVel);
	Vector2 Arrive(Vector2 targetPos);
	Vector2 Wander();
	Vector2 WallCollision(Wall wall);

public:
	Agent();
	Agent(Vector2 position, Vector2 velocity) : position(position), velocity(velocity), maxAcceleration(200), wanderAngle(0), chase(Vector2{0 , 0}), maxSpeed(100), state(1) {};
	void CheckState();
	void Update(Vector2 target, Vector2 targetVel, Agent agents[], Wall walls[]);
	void Draw();
};
