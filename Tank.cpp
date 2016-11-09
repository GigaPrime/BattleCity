#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "Tank.h"
#include "Constants.h"
#include "Collisions.h"
using namespace std;

Tank testTank;

void handleTank()
{
	if (testTank.isAlive)
	{
		Tank newState = chageTankState(testTank);

		if (checkCollision(newState))
		{
			testTank.x = false;
		}
		else
		{
			testTank = newState;
		}
	}
	else
	{
		if (_kbhit())
		{
			char action = _getch();
			if (action == FIRE)
			{
				testTank = newTank();
			}
		}
	}
}

Tank newTank()
{
	Tank newTank;
	newTank.x = 0;
	newTank.y = 0;
	newTank.direction;
	newTank.isAlive = true;

	if (_kbhit())
	{
		char action = _getch();
		if (action == 'w')
			newTank.direction = UP;
		else if (action == 'd')
			newTank.direction = RIGHT;
		else if (action == 's')
			newTank.direction = DOWN;
		else if (action == 'a')
			newTank.direction = LEFT;
	}

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