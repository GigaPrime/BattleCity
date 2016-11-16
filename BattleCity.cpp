#include <conio.h>
#include <time.h>
#include "Round.h"
#include "Tank.h"
#include "Collisions.h"
#include "Constants.h"
#include "BattleCity.h"
#include "RenderConsole.h"
#include "Utils.h"

Tank player, prevPlayer;

Tank aiTanks[MAX_ENEMIES];
Tank prevAiTanks[MAX_ENEMIES];

COORD playerStart = PLAYER_RESP;

void Game()
{
	srand(time(0));
	showBounds();
	runBattle();
}

void runBattle()
{
	player = newTank(playerStart, UP);

	aiTanks[0] = newAiTank(TOP_LEFT_RESP, DOWN);
	aiTanks[1] = newAiTank(TOP_CENTER_RESP, DOWN);
	aiTanks[2] = newAiTank(TOP_RIGHT_RESP, DOWN);

	while (true)
	{
		handlePlayerInput();
		handleAiInput();
		handlePlayerRounds();
		handleAiRounds();
		render();
		Sleep(MAIN_LOOP_SLEEP);
	}
}

void handlePlayerInput()
{
	if (_kbhit())
	{
		int direction = -1;
		char action = _getch();
		if (action == 'd')
			direction = RIGHT;
		else if (action == 's')
			direction = DOWN;
		else if (action == 'a')
			direction = LEFT;
		else if (action == 'w')
			direction = UP;
		else if (action == FIRE && !player.round.isActive)
			player.round = newRound(player);

		if (direction != -1)
		{			
			Tank newPlayerState = chageTankState(player, direction);

			if (!checkCollision(newPlayerState) && 
				!checkCollision(newPlayerState, aiTanks))
			{
				prevPlayer = player;
				player = newPlayerState;
			}
		}
	}
}

void handleAiInput()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		Tank& tank = aiTanks[i];
		Tank& prevTank = prevAiTanks[i];

		if (tank.isAlive == false)
		{
			if (tank.respawnTimer.counter-- <= 0)
			{
				Tank nAiTank = newAiTank(TOP_CENTER_RESP, NO_DIRECTION, INITAIL_TANK_RESP_TIMER);
			
				if (checkCollision(nAiTank, player) ||
					checkCollision(nAiTank, tank, aiTanks))
				{
					changeAiTankDirection(tank);
				}
				else
				{
					tank = nAiTank;
				}
			}
			continue;
		}

		if (tank.directionTimer.isAlive)
		{
			tank.directionTimer.counter--;
		}		

		if (tank.roundTimer.isAlive)
		{
			tank.roundTimer.counter--;
		}

		if (tank.round.isActive == false && tank.roundTimer.counter <= 0)
		{
			tank.round = newRound(tank);
		}
		else
		{
			Tank newAiState = chageTankState(tank);

			if (checkCollision(newAiState) ||
				checkCollision(newAiState, player) ||
				checkCollision(newAiState, tank, aiTanks) ||
				tank.directionTimer.counter <= 0)
			{
				changeAiTankDirection(tank);
			}
			else if (checkCollision(newAiState, player.round))
			{
				killTank(tank);
			}
			else
			{
				prevTank = tank;
				tank = newAiState;
			}
		}
	}
}

void handlePlayerRounds()
{
	if (player.round.isActive)
	{
		Round newRoundState = chageRoundState(player.round);
		prevPlayer.round = player.round;
		if (!checkCollision(newRoundState) && !playerRoundCollisionAiTank(newRoundState))
		{
			player.round = newRoundState;
		}
		else
		{
			killRound(player.round);
		}
	}
}

void handleAiRounds()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		Round& round = aiTanks[i].round;
		Round& prevRound = prevAiTanks[i].round;

		Round newRoundState = chageRoundState(round);
		prevRound = round;
		if (!checkCollision(newRoundState))
		{
			round = newRoundState;
		}
		else
		{
			killRound(round);
		}
	}
}

void render()
{
	unrender(prevPlayer);
	unrender(prevAiTanks);
//---------------------------------------
	render(player);
	render(aiTanks);
}

void showBounds()
{
	renderBounds();
}

bool playerRoundCollisionAiTank(Round round)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (aiTanks[i].isAlive == false)
		{
			continue;
		}
		bool impact = checkCollision(round, aiTanks[i]);
		if (impact)
		{
			killTank(aiTanks[i]);
			return true;
		}
	}
	return false;
}
