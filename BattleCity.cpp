#include <Windows.h>
#include <Conio.h>
#include "Round.h"
#include "Tank.h"
#include "Collisions.h"
#include "Constants.h"
#include "BattleCity.h"
#include "RenderConsole.h"

Tank player, prevPlayer;

void Game()
{
	showBounds();
	runBattle();
}

void runBattle()
{
	COORD coord = { 2, 2 };
	player = newTank(coord, DOWN);

	while (true)
	{
		handlePlayerInput();
		handleAiInput();
		handlePlayerRounds();
		handleAiInput();
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
		else if (action == ' ')
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
}

void showBounds()
{
	renderBounds();
}

//if (player.isAlive)
//{
//	Tank newState = chageTankState(player);
//
//	if (checkCollision(newState))
//	{
//		player.x = false;
//	}
//	else
//	{
//		testTank = newState;
//	}
//}
//else
//{
//	if (_kbhit())
//	{
//		char action = _getch();
//		if (action == RIGHT)
//		{
//			testTank = newTank();
//		}
//	}


