#include "Tank.h"
#include "Round.h"

#ifndef __RENDERCONSOLE_H__
#define __RENDERCONSOLE_H__

void renderBounds();

void render(Tank player);
void render(Round round);

void unrender(Tank player);
void unrender(Round round);

#endif // !__RENDERCONSOLE_H__
