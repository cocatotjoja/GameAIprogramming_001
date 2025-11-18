#pragma once
#include <iostream>
#include <array>
#include "raylib.h"
#include "raymath.h"
#include "wall.h"
#include "obstacle.h"

class Agent
{
private:
	Vector2 position;
	Vector2 velocity;
	float radius;
	float maxAcceleration;
	float wanderAngle;
	Vector2 chase;
	Color color = { 176, 190, 162, 255 };
	float maxSpeed;
	int state;
	int ID;
	//int timePassed = 0;

	bool frontCollision = false;
	bool rightCollision = false;
	bool leftCollision = false;

	Vector2 Seek(Vector2 targetPos);
	Vector2 Flee(Vector2 targetPos);
	Vector2 Pursue(Vector2 targetPos, Vector2 targetVel);
	Vector2 Evade(Vector2 targetPos, Vector2 targetVel);
	Vector2 Arrive(Vector2 targetPos);
	Vector2 Wander();
	Vector2 WallCollision(Wall wall);
	Vector2 ObstacleCollision(Vector2 obstaclePositon, float ObstacleRadius);
	Vector2 AgentCollision(Agent agent);
	void ScreenWrap(float width, float height);

public:
	Agent();
	Agent(int id, int width, int height, int margin);
	Agent(Vector2 position, Vector2 velocity, int ID) : position(position), velocity(velocity), radius(20), maxAcceleration(200), wanderAngle(0), chase(Vector2{0 , 0}), maxSpeed(100), state(6), ID(ID) {};
	void CheckState();
	void Update(Vector2 target, Vector2 targetVel, Agent agents[], Wall walls[], Obstacle obstacles[], float width, float height);
	void Draw();
	Vector2 GetPosition();
	Vector2 GetVelocity();
	float GetRadius();
	int GetID();
};
