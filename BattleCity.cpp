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
		if (tank.directionTimer.isAlive)
		{
			tank.directionTimer.counter--;
		}
		else
		{
			tank.isAlive = false;
		}

		Tank newAiState = chageTankState(tank);

		if (checkCollision(newAiState) ||
			checkCollision(newAiState, player) ||
			checkCollision(newAiState, tank, aiTanks) ||
			tank.directionTimer.counter <= 0)
		{
			aiTanks[i] = changeAiTankDirection(tank);
		}
		else
		{
			prevAiTanks[i] = tank;
			aiTanks[i] = newAiState;
		}
	}
}

void handlePlayerRounds()
{
	
	if (player.round.isActive)
	{
		Round newRoundState = chageRoundState(player.round);
		prevPlayer.round = player.round;
		if (!checkCollision(newRoundState) &&
			!checkCollision(newRoundState, aiTanks[0]) &&
			!checkCollision(newRoundState, aiTanks[1]) && 
			!checkCollision(newRoundState, aiTanks[2]))
		{
			player.round = newRoundState;
		}
		else
		{
			player.round.isActive = false;
		}
	}
}

void handleAiRounds()
{

}

void render()
{
	unrender(prevPlayer);
	unrender(prevPlayer.round);
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		unrender(prevAiTanks[i]);
	}
	
//---------------------------------------
	render(player);
	render(player.round);
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		render(aiTanks[i]);
	}
}

void showBounds()
{
	renderBounds();
}

