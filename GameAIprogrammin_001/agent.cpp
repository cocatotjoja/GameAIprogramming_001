#include "agent.h"
#include "raylib.h"

void Agent::Update(Vector2 target)
{
	switch (state)
	{
		case 1:
			Seek(target);
			break;
		case 2:
			Flee(target);
			break;
		case 3:
			Pursue(target);
			break;
		case 4:
			Evade(target);
			break;
		case 5:
			Arrive(target);
			break;
		case 6:
			Wander(target);
			break;
		default:
			break;
	}
}

void Agent::Draw(Color color)
{

}