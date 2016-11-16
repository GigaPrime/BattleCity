#include "Tank.h"
#include "Round.h"

#ifndef __RENDERCONSOLE_H__
#define __RENDERCONSOLE_H__

void renderBounds();

void render(Tank player);
void render(Round round);
void render(Tank tanks[]);

void unrender(Tank player);
void unrender(Round round);
void unrender(Tank tanks[]);

#endif // !__RENDERCONSOLE_H__
