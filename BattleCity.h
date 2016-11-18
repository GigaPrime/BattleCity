#include "Round.h"
#include "Tank.h"

#ifndef __BATTLECITY_H__
#define __BATTLECITY_H__

void showIntro();
void showBounds();

void runBattle();
void handlePlayerInput();
void handleAiInput();
void handlePlayerRounds();
void handleAiRounds();
void render();


void Game();

bool playerRoundCollisionAiTank(Round round);

#endif // !__BATTLECITY_H__
