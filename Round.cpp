#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "Round.h"
#include "Constants.h"
#include "ConsoleLib.h"
#include "Collisions.h"
using namespace std;




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

