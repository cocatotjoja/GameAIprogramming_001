#include "agent.h"


Agent::Agent()
{
	position = Vector2{ (float)GetRandomValue(40, 700), (float)GetRandomValue(40, 700) };
	velocity = Vector2{ 0 , 0 };
	maxAcceleration = 200;
	wanderAngle = 0;
	chase = Vector2{ 0 , 0 };
	maxSpeed = 100;
	state = 1;
}
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

void Agent::Update(Vector2 targetPos, Vector2 targetVel, Agent agents[], Wall walls[])
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
			velocity += Wander() * GetFrameTime();
			break;
		default:
			break;
	}
	if (Vector2Length(velocity) > maxSpeed)
	{
		velocity = Vector2Normalize(velocity);
		velocity *= maxSpeed;
	}

	// Check wall collisions
	for (int i = 0; i < 4; i++)
	{
		Vector2 collision = WallCollision(walls[i]);
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

	//give max acceleration
	result = Vector2Normalize(result) * maxAcceleration;


	return result;
}

Vector2 Agent::Flee(Vector2 targetPos)
{
	// Update chase (DEBUG)
	chase = targetPos;

	// Calculate velocity
	Vector2 result = position - targetPos;

	//give max acceleration
	result = Vector2Normalize(result) * maxAcceleration;


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

Vector2 Agent::Wander()
{
	float wanderOffset = 200;
	float wanderRadius = wanderOffset/2;
	float wanderRate = 0.1;
	int randomOffset = GetRandomValue(-10, 10);
	Vector2 velocityNormalized = Vector2Normalize(velocity);
	if (randomOffset != 0)
	{
		randomOffset /= abs(randomOffset);
	}

	wanderAngle += randomOffset * wanderRate;
	Vector2 wanderTarget = Vector2Rotate(velocityNormalized, wanderAngle);

	Vector2 target = position + (velocityNormalized * wanderOffset);
	target += wanderTarget * wanderRadius;


	return Seek(target);
}

Vector2 Agent::WallCollision(Wall wall)
{
	Vector2 raycastEnd = position + (velocity * 10);
	Vector2 collisionPoint{ 0,0 };
	Vector2 collisionNormal{ 0,0 };

	// Check for collision
	bool colliding = CheckCollisionLines(position, raycastEnd, wall.GetStart(), wall.GetEnd(), &collisionPoint);

	//If there is a collision, calculate the collsion normal
	if (colliding)
	{
		// Test which direction the collision normal is going, and return the correct one
		Vector2 wallVector = wall.GetVector();
		float angle = Vector2Angle(velocity * 10, Vector2{ -wallVector.y, wallVector.x });
		float angleDeg = angle * (180.0 / 3.141592653589793238463);
		if (angleDeg < 90.0)
		{
			return Vector2{ -wallVector.y, wallVector.x };
		}
		else
		{
			return Vector2{ wallVector.y, -wallVector.x };
		}
	}
	// If there was no collision return a Vector zero 
	else
	{
		return Vector2{ 0,0 };
	}
}

