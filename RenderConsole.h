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

void render(Tank player);
void render(Round round);
void render(Tank tanks[]);

void unrender(Tank player);
void unrender(Round round);
void unrender(Tank tanks[]);

void renderBounds();
void renderGameName(Letter);

#endif // !__RENDERCONSOLE_H__
