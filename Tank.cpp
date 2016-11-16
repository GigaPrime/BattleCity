#include "Tank.h"
#include "Constants.h"
#include "Utils.h"
#include "Timer.h"
using namespace std;

Tank newTank(COORD coord, int direction)
{
	Tank newTank;
	newTank.x = coord.X;
	newTank.y = coord.Y;
	newTank.direction = direction;
	newTank.isAlive = true;
	newTank.round = { 0, 0, false, -1 };
	newTank.directionTimer = { false, -1 };
	newTank.respawnTimer = { false, -1 };
	return newTank;
}

Tank newAiTank(COORD coord, int direction)
{
	Tank tank = newTank(coord, direction);
	tank.directionTimer = newTimer(getRndTime(MIN_ENEMY_KEEP_DIRECTION_TIME, MAX_ENEMY_KEEP_DIRECTION_TIME));
	return tank;
}

Tank chageTankState(Tank tank)
{
	double deltaH = TANK_SPEED_H / FPS;
	double deltaV = TANK_SPEED_V / FPS;

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

Tank chageTankState(Tank tank, int direction)
{
	if (tank.direction == direction)
	{
		switch (tank.direction)
		{
		case RIGHT:
			tank.x++;
			break;
		case DOWN:
			tank.y++;
			break;
		case LEFT:
			tank.x--;
			break;
		case UP:
			tank.y--;
			break;
		}
	}
	else
	{
		tank.direction = direction;
	}

	return tank;
}

Round newRound(Tank& tank)
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
	tank.roundTimer = newTimer(getRndTime(MIN_ENEMY_KEEP_DIRECTION_TIME, MAX_ENEMY_KEEP_DIRECTION_TIME));
	return newRound;
}

Tank newAiTank(COORD coord, int direction, double timer)
{
	Tank tank = newTank(coord, direction);
	tank.directionTimer = newTimer(timer);
	return tank;
}

void changeAiTankDirection(Tank& tank)
{
	tank.direction = getRndNumber(TOTAL_DIRECTIONS);
	tank.directionTimer = newTimer(getRndTime(MIN_ENEMY_KEEP_DIRECTION_TIME, MAX_ENEMY_KEEP_DIRECTION_TIME));
}

void killTank(Tank& tank)
{
	tank.isAlive = false;
	tank.respawnTimer = newTimer(TANK_RESP_TIMER);
}

