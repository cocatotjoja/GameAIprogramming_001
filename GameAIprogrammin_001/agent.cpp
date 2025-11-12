#include "agent.h"


void Agent::CheckState()
{
	if (IsKeyDown(KEY_ONE))
	{
		// Seek
		state = 1;
	}
	if (IsKeyDown(KEY_TWO))
	{
		// Flee
		state = 2;
	}
	if (IsKeyDown(KEY_THREE))
	{
		// Pursue
		state = 3;
	}
	if (IsKeyDown(KEY_FOUR))
	{
		// Evade
		state = 4;
	}
	if (IsKeyDown(KEY_FIVE))
	{
		// Arrive
		state = 5;
	}
	if (IsKeyDown(KEY_SIX))
	{
		// Wander
		state = 6;
	}
}

void Agent::Update(Vector2 targetPos, Vector2 targetVel)
{
	// Update Velocity
	switch (state)
	{
		case 1:
			velocity += Seek(targetPos) * GetFrameTime();
			break;
		case 2:
			velocity += Flee(targetPos) * GetFrameTime();
			break;
		case 3:
			velocity += Pursue(targetPos, targetVel) * GetFrameTime();
			break;
		case 4:
			velocity += Evade(targetPos, targetVel) * GetFrameTime();
			break;
		case 5:
			velocity += Arrive(targetPos) * GetFrameTime();
			break;
		case 6:
			velocity += Wander(targetPos) * GetFrameTime();
			break;
		default:
			break;
	}
	if (Vector2Length(velocity) > maxSpeed)
	{
		velocity = Vector2Normalize(velocity);
		velocity *= maxSpeed;
	}

	// Update position
	position += velocity * GetFrameTime();
}

void Agent::Draw()
{
	DrawCircle(position.x, position.y, 20, color);
	DrawCircle(chase.x, chase.y, 5, color);
}

Vector2 Agent::Seek(Vector2 targetPos)
{
	// Update chase (DEBUG)
	chase = targetPos;

	// Calculate velocity
	Vector2 result = targetPos - position;
	return result;
}

Vector2 Agent::Flee(Vector2 targetPos)
{
	// Update chase (DEBUG)
	chase = targetPos;

	// Calculate velocity
	Vector2 result = position - targetPos;
	return result;
}

Vector2 Agent::Pursue(Vector2 targetPos, Vector2 targetVel)
{
	float maxTime = 480 * 100;
	float distance = Vector2Distance(targetPos, position);
	float time = distance / Vector2Length(velocity);
	
	// TEST
	time *= 4; 
	if (time > maxTime)
	{
		time = maxTime;
	}
	Vector2 target = targetPos + (targetVel * time);
	
	// Update chase (DEBUG)
	chase = target;

	return Seek(target);
}

Vector2 Agent::Evade(Vector2 targetPos, Vector2 targetVel)
{
	float maxTime = 480 * 100;
	float distance = Vector2Distance(targetPos, position);
	float time = distance / Vector2Length(velocity);

	// TEST
	time *= 4;
	if (time > maxTime)
	{
		time = maxTime;
	}
	Vector2 target = targetPos + (targetVel * time);

	// Update chase (DEBUG)
	chase = target;

	return Flee(target);
}

Vector2 Agent::Arrive(Vector2 targetPos)
{
	// Update chase (DEBUG)
	chase = targetPos;

	float maxAcceleration = 100;
	float goalSpeed;
	float targetRadius = 20;
	float slowRadius = 300;
	float timeToTarget = 0.1;
	Vector2 direction = targetPos - position;
	float distance = Vector2Length(direction);

	// Are we there yet?
	if (distance < targetRadius)
	{
		return Vector2Negate(velocity);
		color = { 111, 50, 60, 255 };
	}

	// If it's far, move fast
	if (distance > targetRadius)
	{
		goalSpeed = maxSpeed;
	}
	else
	{
		goalSpeed = maxSpeed * distance / slowRadius;
	}

	// Calculate goal velocity
	Vector2 result = Vector2Normalize(direction);
	result *= goalSpeed;

	//Take current velocity into account
	result -= velocity;
	result /= timeToTarget;

	//give max acceleration
	result = Vector2Normalize(result) * maxAcceleration;


	return result;
}

Vector2 Agent::Wander(Vector2 targetPos)
{
	return Vector2();
}
