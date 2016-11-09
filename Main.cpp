#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "Round.h"
#include "Tank.h"
#include "Sprites.h"
#include "Constants.h"
#include "Collisions.h"
#include "ConsoleLib.h"
using namespace std;

int render(Tank tank);
int unrender(Tank tank);
int render(Round round1);
int render2(Round round2);
int unrender(Round round1);

// tank & rounds collision check
int main() 
{
	Tank t1 = {3, 3, 1, 1};
	Tank t2 = {10, 10, 1, 1 };
	Round round1 = {5, 5, true, 2};
	Round round2 = { 10, 10, true, 2 };

	for (int i = 0; i < 10; ++i) {
		
		GotoXY(0, i);

		t1.x++;
		t1.y++;

		round1.x++;
		round1.y++;

		//cout << (checkCollision(t1, t2) ? "true" : "false") << "; t1.x = " << t1.x << ", t1.y = " << t1.y << ", t2.x = " << t2.x << ", t2.y = " << t2.y << endl;
		//cout << (checkCollision(t1, round) ? "true" : "false") << "; t1.x = " << t1.x << "t1.y = " << t1.y << ", round.x = " << round.x << ", round.y = " << round.y << endl;
		cout << (checkCollision(t1, round2) ? "true" : "false") << "; t1.x = " << t1.x << "round1.y = " << round1.y << ", round2.x = " << round2.x << ", round2.y = " << round2.y << endl;

		render(t1);
		//render(t2);
		//render(round1);
		render2(round2);

		Sleep(2500);

		unrender(t1);
		//unrender(t2);
		//unrender(round1);
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

int render(Round round1)
{
	//handleRound();
	return 0;
}

int render2(Round round2)
{
	WriteChar(round2.x, round2.y, '*');
	return 0;
}

int unrender(Round round1)
{
	WriteChar(round1.x, round1.y, ' ');
	
	return 0;
}

