#include <windows.h>
#include "Round.h"
#include "Timer.h"
#include "ConsoleLib.h"

#ifndef __TANK_H__
#define __TANK_H__

struct Tank 
{
	double x;
	double y;
	bool isAlive;
	int direction;
	Round round;
	Timer directionTimer;
	Timer respawnTimer;
	Timer roundTimer;
	ConsoleColor tankColor;
};

Tank chageTankState(Tank tank);
Tank chageTankState(Tank tank, int direction);
Round newRound(Tank& tank);
Tank newTank(COORD coord, int direction);
Tank newAiTank(COORD coord, int direction);
Tank newAiTank(COORD coord, int direction, double timer);
void changeAiTankDirection(Tank& tank);
void killTank(Tank& tank);

#endif // !__TANK_H__
