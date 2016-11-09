#include "Tank.h"
#include "Constants.h"

#ifndef __BATTLECITY_H__
#define __BATTLECITY_H__

Tank Player;
Tank AI[MAX_ENEMIES];

void runBattle();
void handlePlayerInput();
void handleAiInput();
void render();

#endif // !__BATTLECITY_H__
