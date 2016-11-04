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

#endif // !__TANK_H__

