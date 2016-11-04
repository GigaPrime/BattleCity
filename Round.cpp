#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "Round.h"
#include "Tank.h"
#include "Constants.h"
#include "ConsoleLib.h"
using namespace std;

void handleRound();
void renderRound();
Round chageRoundState(Round round);
Round testRound;
bool roundCollision(Round round);
Round newRound();

void handleRound()
{
	if (testRound.isActive)
	{
		Round newState = chageRoundState(testRound);

		if (roundCollision(newState))
		{
			testRound = newState;
		}
		else
		{
			testRound.isActive = false;
		}
	}
	else
	{
		if (_kbhit())
		{
			char action = _getch();
			if (action == FIRE)
			{
				testRound = newRound();
			}
		}
	}
}

Round newRound()
{
	Round newRound;
	newRound.x = 0;
	newRound.y = 0;
	newRound.direction = RIGHT;
	newRound.isActive = true;
	return newRound;
}

bool roundCollision(Round round)
{
	switch (round.direction)
	{
	case RIGHT:
	case LEFT:
		return round.x >= 0 && round.x <= WIDTH;
	case UP:
	case DOWN:
		return round.y >= 0 && round.y <= HEIGHT;
	}
}

Round chageRoundState(Round round)
{
	double deltaH = ROUND_SPEED_H / FPS;
	double deltaV = ROUND_SPEED_V / FPS;

	switch (round.direction)
	{
	case RIGHT:
		round.x += deltaH;
		break;
	case DOWN:
		round.y += deltaV;
		break;
	case LEFT:
		round.x -= deltaH;
		break;
	case UP:
		round.y -= deltaV;
		break;
	}
	return round;
}

