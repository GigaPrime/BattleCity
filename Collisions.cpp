#include <windows.h>
#include "Round.h"
#include "Tank.h"
#include "Constants.h"
#include "Utils.h"

bool checkCollision(Tank tank)
{
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH - 1, tank.y + TANK_HEIGHT - 1};

	return (topLeft.X <= FIELD_X) ||
		   (topLeft.Y <= FIELD_Y) ||
		   (bottomRight.X >= FIELD_WIDTH) ||
		   (bottomRight.Y >= FIELD_HEIGHT);
}

bool checkCollision(Round round)
{
	return (round.x <= FIELD_X) ||
		   (round.y <= FIELD_Y) ||
		   (round.x >= FIELD_WIDTH) ||
		   (round.y >= FIELD_HEIGHT);
}

bool checkCollision(Tank tank1, Tank tank2)
{
	COORD topLeftT2 = { tank2.x, tank2.y };
	COORD bottomRightT2 = { tank2.x + TANK_WIDTH - 1, tank2.y + TANK_HEIGHT - 1 };

	COORD topLeftT1 = { tank1.x, tank1.y };
	COORD topRightT1 = { tank1.x + TANK_WIDTH - 1, tank1.y };
	COORD bottomLeftT1 = { tank1.x, tank1.y + TANK_HEIGHT - 1 };
	COORD bottomRightT1 = { tank1.x + TANK_WIDTH - 1, tank1.y + TANK_HEIGHT - 1 };

	return isPointWithinRectangle(topLeftT1, topLeftT2, bottomRightT2) || 
		   isPointWithinRectangle(topRightT1, topLeftT2, bottomRightT2) ||
		   isPointWithinRectangle(bottomLeftT1, topLeftT2, bottomRightT2) ||
		   isPointWithinRectangle(bottomRightT1, topLeftT2, bottomRightT2);
}

bool checkCollision(Round round, Tank tank)
{
	COORD roundFlight = { round.x, round.y };
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH - 1, tank.y + TANK_HEIGHT - 1 };

	return isPointWithinRectangle(roundFlight, topLeft, bottomRight);
}

bool checkCollision(Tank tank, Round round)
{
	return checkCollision(round, tank);
}

bool checkCollision(Round round1, Round round2)
{
	COORD roundFlight1 = { round1.x, round1.y };
	COORD roundFlight2 = { round2.x, round2.y };

	return (round1.x == round2.x && round1.y == round2.y);
}

bool checkCollision(Tank tank, Tank tanks[])
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (checkCollision(tank, tanks[i]))
		{
			return true;
		}
	}
	return false;
}

bool checkCollision(Tank tankProjection, Tank tank, Tank tanks[])
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (tank.x == tanks[i].x && tank.y == tanks[i].y)
		{
			continue;
		}
		if (checkCollision(tankProjection, tanks[i]))
		{
			return true;
		}
	}
	return false;
}


/*collision check
1. player to bounds;
2. player to AI;
3. player to round;
4. AI to bounds;
5. AI to player;
6. AI to player's round;
7. AI to AI;
8. palyer's round to bounds;
9. player's round to AI;
10. AI round to bounds;
11. AI round to player;
*/

/*
abstract collision check
1. tank to bounds;
2. round to bounds;
3. round to tank;
4. tank to tank;
*/
