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

Tank aiTanks[MAX_ALIVE_ENEMIES];
Tank prevAiTanks[MAX_ALIVE_ENEMIES];

Letter letter;
Counter counter;

int killCounter = 0;

COORD playerStart = PLAYER_RESP;

void Game()
{
	srand(time(0));
	showIntro();
	showBounds();
	runBattle();
}

void runBattle()
{
	player = newTank(playerStart, UP);

	aiTanks[0] = newAiTank(TOP_LEFT_RESP, DOWN);
	aiTanks[1] = newAiTank(TOP_CENTER_RESP, DOWN);
	aiTanks[2] = newAiTank(TOP_RIGHT_RESP, DOWN);

	while (killCounter < 20)
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
	int direction = -1;
	Tank newPlayerState = newTank(PLAYER_RESP, UP);

	if (player.isAlive)
	{
		if (_kbhit())
		{
			//int direction = -1;
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
				newPlayerState = chageTankState(player, direction);

				if (!checkCollision(newPlayerState) &&
					!checkCollision(newPlayerState, aiTanks))
				{
					prevPlayer = player;
					player = newPlayerState;
				}
			}
		}
	}
	else
	{
		if(!checkCollision(newPlayerState, aiTanks))
		player = newTank(PLAYER_RESP, UP);
	}
}

void handleAiInput()
{
	for (int i = 0; i < MAX_ALIVE_ENEMIES; i++)
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
	for (int i = 0; i < MAX_ALIVE_ENEMIES; i++)
	{
		Round& round = aiTanks[i].round;
		Round& prevRound = prevAiTanks[i].round;

		Round newRoundState = chageRoundState(round);
		prevRound = round;
		if (!checkCollision(newRoundState) && !checkCollision(newRoundState, player))
		{
			round = newRoundState;
		}
		else if (checkCollision(newRoundState, player))
		{
			killTank(player);
			killRound(round);
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

void showIntro()
{
	letter.x = GAME_NAME_START_X;
	letter.y = GAME_NAME_START_Y;
	letter.letterNumber = B;

	for (int x = 0; x < 5; x++) // 5 unique letters quantitiy in the first string
	{
		renderGameName(letter);
		letter.x += CHARS_DIST;
		letter.letterNumber++;

		if (letter.letterNumber == L)
		{
			letter.letterNumber = T;
			renderGameName(letter);
			letter.x += CHARS_DIST;
			letter.letterNumber++;
		}
	}

	letter.x = GAME_NAME_START_X * 2.4;
	letter.y = GAME_NAME_START_Y * 2.5;

	for (int x = 0; x < 3; x++) // 3 unique letters quantitiy in the second string
	{
		renderGameName(letter);
		letter.x += CHARS_DIST;
		letter.letterNumber++;

		if (letter.letterNumber == Y)
		{
			letter.letterNumber = T;
			renderGameName(letter);
			letter.x += CHARS_DIST;
			letter.letterNumber = Y;
		}
	}
}

void showCounter(int killCounter)
{
		counter.x1 = COUNTER_X;
		counter.x2 = COUNTER_X + 3;
		counter.y = COUNTER_Y;
		counter.digitNumber1 = killCounter / 10;
		counter.digitNumber2 = killCounter % 10;
		renderCounter(counter);
}

bool playerRoundCollisionAiTank(Round round)
{
	for (int i = 0; i < MAX_ALIVE_ENEMIES; i++)
	{
		if (aiTanks[i].isAlive == false)
		{
			continue;
		}
		bool impact = checkCollision(round, aiTanks[i]);
		if (impact)
		{
			killTank(aiTanks[i]);
			killCounter++;
			showCounter(killCounter);
			return true;
		}
	}
	return false;
}
