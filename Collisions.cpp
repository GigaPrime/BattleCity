#include <windows.h>
#include "Round.h"
#include "Tank.h"
#include "Constants.h"

bool checkCollision(Tank tank)
{
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH, tank.y + TANK_HEIGHT };

	return (topLeft.X <= FIELD_X) ||
		(topLeft.Y <= FIELD_Y) ||
		(bottomRight.X >= FIELD_X + FIELD_WIDTH) ||
		(bottomRight.Y >= FIELD_Y + FIELD_WIDTH);
}

bool checkCollision(Round round)
{
	COORD roundFlight = { round.x, round.y };

	return (round.x <= FIELD_X) ||
		(round.y <= FIELD_Y) ||
		(round.x >= FIELD_X + FIELD_WIDTH) ||
		(round.y >= FIELD_Y + FIELD_HEIGHT);
}

bool checkCollision(Tank tank1, Tank tank2)
{
	COORD topLeftT1 = { tank1.x, tank1.y };
	COORD topLeftT2 = { tank2.x, tank2.y };
	COORD bottomRightT1 = { tank1.x + TANK_WIDTH, tank1.y + TANK_HEIGHT };
	COORD bottomRightT2 = { tank2.x + TANK_WIDTH, tank2.y + TANK_HEIGHT };

	return (topLeftT2.X > topLeftT1.X && topLeftT2.Y > topLeftT1.Y && topLeftT2.X < bottomRightT1.X && topLeftT2.Y < bottomRightT1.Y) ||
		(bottomRightT2.X > topLeftT1.X && bottomRightT2.Y > topLeftT1.Y && bottomRightT2.X < bottomRightT1.X && bottomRightT2.Y < bottomRightT1.Y) ||
		(topLeftT1.X == topLeftT2.X && topLeftT1.Y == topLeftT2.Y);
}

bool checkCollision(Round round, Tank tank)
{
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH, tank.y + TANK_HEIGHT };
	COORD roundFlight = { round.x, round.y };

	return (round.x >= topLeft.X && round.x <= bottomRight.X && round.y >= topLeft.Y && round.y < bottomRight.Y);
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
