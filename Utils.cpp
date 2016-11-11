#include <Windows.h>
#include "Utils.h"

bool isPointWithinRectangle(COORD point, COORD topLeft, COORD bottomRight)
{
	return (point.X >= topLeft.X && point.X <= bottomRight.X && 
		    point.Y >= topLeft.Y && point.Y <= bottomRight.Y);
}

int getRndNumber(int bound)
{
	return rand() % bound;
}

int getRndNumber(int lBound, int hBound)
{
	return rand() % (hBound - lBound) + lBound;
}

double getRndTime(double lBound, double hBound) 
{
	return (getRndNumber(lBound * 10, hBound * 10) * 1.0) / 10;
}
