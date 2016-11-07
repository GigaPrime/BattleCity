#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "Round.h"
#include "Tank.h"
#include "Sprites.h"
#include "Constants.h"
#include "ConsoleLib.h"
using namespace std;

int render(Tank tank);
int unrender(Tank tank);
int render(Round round);
int unrender(Round round);

bool checkCollision(Tank tank); // tank to bound collision;
bool checkCollision(Round round); // round to bound collision;
bool checkCollision(Tank tank1, Tank tank2); // tank to tank collision;
bool checkCollision(Round round, Tank tank); // round to tank collision;
bool checkCollision(Tank tank, Round round); // round to tank collision;
bool checkCollision(Round round1, Round round2); // round to round collision;


int main()
{
	Tank t1 = {8, 8, 1, 1};
	Tank t2 = {10, 10, 1, 1 };
	Round round1 = {5, 5, true, 2};
	Round round2 = { 10, 10, true, 2 };

	for (int i = 0; i < 10; ++i) {
		
		GotoXY(0, i);

		//t2.x++;
		//t2.y++;

		round1.x++;
		round1.y++;

		//cout << (checkCollision(t1, t2) ? "true" : "false") << "; t1.x = " << t1.x << ", t1.y = " << t1.y << ", t2.x = " << t2.x << ", t2.y = " << t2.y << endl;
		//cout << (checkCollision(t1, round) ? "true" : "false") << "; t1.x = " << t1.x << "t1.y = " << t1.y << ", round.x = " << round.x << ", round.y = " << round.y << endl;
		cout << (checkCollision(round1, round2) ? "true" : "false") << "; round1.x = " << round1.x << "round1.y = " << round1.y << ", round2.x = " << round2.x << ", round2.y = " << round2.y << endl;

		//render(t1);
		//render(t2);
		render(round1);
		render(round2);

		Sleep(2500);

		//unrender(t1);
		//unrender(t2);
		unrender(round1);
		unrender(round2);
	}
}

int render(Tank tank)
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			WriteChar(x + tank.x, y + tank.y, tankSprites[0][y][x]);
		}
	}
	return 0;
}

int unrender(Tank tank)
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			WriteChar(x + tank.x, y + tank.y, ' ');
		}
	}
	return 0;
}

int render(Round round)
{
	WriteChar(round.x, round.y, '*');
	return 0;
}

int unrender(Round round)
{
	WriteChar(round.x, round.y, ' ');
	
	return 0;
}

/*collision check
1. player to bounds;
2. player to AI;
3. player to round;
4. AI to bounds;
5. AI to player;
6. AI to player's round;
7. AI to AI;
8. palyer's round to bounds;
9. player's round to AI;
10. AI round to bounds;
11. AI round to player;
*/

/*
abstract collision check
1. tank to bounds;
2. round to bounds;
3. round to tank;
4. tank to tank;
*/


bool checkCollision(Tank tank)
{
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH, tank.y + TANK_HEIGHT };

	return (topLeft.X <= FIELD_X) ||
		   (topLeft.Y <= FIELD_Y) ||
		   (bottomRight.X >= FIELD_X + FIELD_WIDTH) ||
		   (bottomRight.Y >= FIELD_Y + FIELD_WIDTH);
}

bool checkCollision(Round round)
{
	COORD roundFlight = { round.x, round.y };

	return (round.x <= FIELD_X) ||
		   (round.y <= FIELD_Y) ||
		   (round.x >= FIELD_X + FIELD_WIDTH) ||
		   (round.y >= FIELD_Y + FIELD_HEIGHT);
}

bool checkCollision(Tank tank1, Tank tank2)
{
	COORD topLeftT1 = { tank1.x, tank1.y };
	COORD topLeftT2 = { tank2.x, tank2.y };
	COORD bottomRightT1 = { tank1.x + TANK_WIDTH, tank1.y + TANK_HEIGHT };
	COORD bottomRightT2 = { tank2.x + TANK_WIDTH, tank2.y + TANK_HEIGHT };

	return (topLeftT2.X > topLeftT1.X && topLeftT2.Y > topLeftT1.Y && topLeftT2.X < bottomRightT1.X && topLeftT2.Y < bottomRightT1.Y) ||
		   (bottomRightT2.X > topLeftT1.X && bottomRightT2.Y > topLeftT1.Y && bottomRightT2.X < bottomRightT1.X && bottomRightT2.Y < bottomRightT1.Y) ||
		   (topLeftT1.X == topLeftT2.X && topLeftT1.Y == topLeftT2.Y);
}

bool checkCollision(Round round, Tank tank) 
{ 
	COORD topLeft = { tank.x, tank.y };
	COORD bottomRight = { tank.x + TANK_WIDTH, tank.y + TANK_HEIGHT };
	COORD roundFlight = { round.x, round.y };

	return (round.x >= topLeft.X && round.x <= bottomRight.X && round.y >= topLeft.Y && round.y < bottomRight.Y);
}

bool checkCollision(Tank tank, Round round) 
{
	return checkCollision(round, tank);
}

bool checkCollision(Round round1, Round round2)
{
	COORD roundFlight1 = { round1.x, round1.y };
	COORD roundFlight2 = { round2.x, round2.y };
	
	return (round1.x == round2.x && round1.y == round2.y);
}
