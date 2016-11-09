#include <windows.h>
#include "Round.h"

#ifndef __TANK_H__
#define __TANK_H__

struct Tank 
{
	double x;
	double y;
	bool isAlive;
	int direction;
	Round round;
};

Tank chageTankState(Tank tank);
Tank chageTankState(Tank tank, int direction);
Round newRound(Tank tank);
Tank newTank(COORD coord, int direction);

#endif // !__TANK_H__
