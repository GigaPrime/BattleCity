#include <Windows.h>
#include <Conio.h>
#include "Round.h"
#include "Tank.h"
#include "Collisions.h"
#include "Constants.h"
#include "BattleCity.h"
#include "RenderConsole.h"

Tank player, prevPlayer;
Tank ai, prevAi;

void Game()
{
	showBounds();
	runBattle();
}

void runBattle()
{
	COORD playerStart = { 30, 20 };
	player = newTank(playerStart, DOWN);

	COORD aiStart = { 40, 30 };
	ai = newTank(aiStart, UP);

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
		else if (action == FIRE)
			player.round = newRound(player);

		if (direction != -1)
		{			
			Tank newPlayerState = chageTankState(player, direction);

			if (!checkCollision(newPlayerState))
			{
				prevPlayer = player;
				player = newPlayerState;
			}
		}
	}
}

void handleAiInput()
{
	Tank newAiState = chageTankState(ai, ai.direction);

	if (checkCollision(newAiState))
	{
		ai.direction = rand() % 4;
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
		if (!checkCollision(newRoundState))
		{
			prevPlayer.round = player.round;
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
	render(player);
	unrender(prevPlayer.round);
	render(player.round);
	unrender(prevAi);
	render(ai);
}

void showBounds()
{
	renderBounds();
}

