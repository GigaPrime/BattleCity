#include "Tank.h"
#include "Round.h"
#include "Constants.h"

#ifndef __RENDERCONSOLE_H__
#define __RENDERCONSOLE_H__

struct Letter
{
	int letterNumber;
	int x;
	int y;
};

struct Counter
{
	int digitNumber1;
	int digitNumber2;
	int x1;
	int x2;
	int y;
};

void render(Tank player);
void render(Round round);
void render(Tank tanks[]);

void unrender(Tank player);
void unrender(Round round);
void unrender(Tank tanks[]);

void renderBounds();
void renderGameName(Letter letter);
void renderCounter(Counter counter);

#endif // !__RENDERCONSOLE_H__
