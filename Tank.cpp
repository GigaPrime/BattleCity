#include <windows.h>
#include "Tank.h"
#include "Constants.h"
using namespace std;

Tank newTank(COORD coord, int direction)
{
	Tank newTank;
	newTank.x = coord.X;
	newTank.y = coord.Y;
	newTank.direction = direction;
	newTank.isAlive = true;
	return newTank;
}

Tank chageTankState(Tank tank)
{
	double deltaH = ROUND_SPEED_H / FPS;
	double deltaV = ROUND_SPEED_V / FPS;

	switch (tank.direction)
	{
	case RIGHT:
		tank.x += deltaH;
		break;
	case DOWN:
		tank.y += deltaV;
		break;
	case LEFT:
		tank.x -= deltaH;
		break;
	case UP:
		tank.y -= deltaV;
		break;
	}
	return tank;
}

Round newRound(Tank tank)
{
	Round newRound;

	if (tank.direction == RIGHT)
	{
		newRound.x = tank.x + TANK_WIDTH;
		newRound.y = tank.y + TANK_HEIGHT / 2;
	}
	else if (tank.direction == DOWN)
	{
		newRound.x = tank.x + TANK_WIDTH / 2;
		newRound.y = tank.y + TANK_HEIGHT;
	}
	else if (tank.direction == LEFT)
	{
		newRound.x = tank.x - 1;
		newRound.y = tank.y + TANK_HEIGHT / 2;
	}
	else if (tank.direction == UP)
	{
		newRound.x = tank.x + TANK_WIDTH / 2;
		newRound.y = tank.y - 1;
	}

	newRound.direction = tank.direction;
	newRound.isActive = true;
	return newRound;
}
