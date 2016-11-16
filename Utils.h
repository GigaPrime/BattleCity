#ifndef __UTILS_H__
#define __UTILS_H__

bool isPointWithinRectangle(COORD point, COORD topLeft, COORD bottomRight);

int getRndNumber(int bound);
int getRndNumber(int lBound, int hBound);
double getRndTime(double lBound, double hBound);

#endif // !__UTILS_H__


// Tank's ski left after tanks' destruction;
// Borders might be broken if tank is close to the border;
