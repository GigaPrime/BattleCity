#include "Tank.h"

#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

bool checkCollision(Tank tank); // tank to bound collision;
bool checkCollision(Round round); // round to bound collision;
bool checkCollision(Tank tank1, Tank tank2); // tank to tank collision;
bool checkCollision(Round round, Tank tank); // round to tank collision;
bool checkCollision(Tank tank, Round round); // round to tank collision;
bool checkCollision(Round round1, Round round2); // round to round collision;

#endif // !__Collisions_H__


