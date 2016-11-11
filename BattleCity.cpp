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
Tank ai, prevAi;

COORD playerStart = { 30, 20 };
COORD aiStart = { 40, 30 };

void Game()
{
	srand(time(0));
	showBounds();
	runBattle();
}

void runBattle()
{
	player = newTank(playerStart, DOWN);
	ai = newAiTank(aiStart, UP);

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
				!checkCollision(newPlayerState, ai))
			{
				prevPlayer = player;
				player = newPlayerState;
			}
		}
	}
}

void handleAiInput()
{
	if (ai.directionTimer.isAlive)
	{
		ai.directionTimer.counter--;	
	}
	
	Tank newAiState = chageTankState(ai);

	if (checkCollision(newAiState) ||
		checkCollision(newAiState, player) ||
		ai.directionTimer.counter <= 0)
	{
		ai = changeAiTankDirection(ai);
	}
	else
	{
		prevAi = ai;
		ai = newAiState;
	}
}

void handlePlayerRounds()
{
	if (player.round.isActive)
	{
		Round newRoundState = chageRoundState(player.round);
		prevPlayer.round = player.round;
		if (!checkCollision(newRoundState))
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
	unrender(prevAi);
	unrender(prevPlayer.round);

	render(player);
	render(ai);
	render(player.round);
}

void showBounds()
{
	renderBounds();
}

