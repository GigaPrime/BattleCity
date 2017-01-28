#include <iostream>
#include "RenderConsole.h"
#include "ConsoleLib.h"
#include "Sprites.h"
using namespace std;

; void render(Tank tank)
{
	render(tank.round);

	if (tank.isAlive == false)
	{
		return;
	}
	SetColor(tank.tankColor, Black);
	for (int x = 0; x < TANK_WIDTH; x++)
	{
		for (int y = 0; y < TANK_HEIGHT; y++)
		{
			WriteChar(x + tank.x, y + tank.y, tankSprites[tank.direction][y][x]);
		}
	}
	SetColor(LightGray, Black);
}

void unrender(Tank tank)
{
	unrender(tank.round);

	for (int x = 0; x < TANK_WIDTH; x++)
	{
		for (int y = 0; y < TANK_HEIGHT; y++)
		{
			WriteChar(x + tank.x, y + tank.y, ' ');
		}
	}
}

void render(Round round)
{
	if(round.isActive)
		WriteChar(round.x, round.y, FR);
}

void unrender(Round round)
{
	WriteChar(round.x, round.y, SP);
}

void render(Tank tanks[])
{
	for (int i = 0; i < MAX_ALIVE_ENEMIES; i++)
	{
		render(tanks[i]);
	}
}

void unrender(Tank tanks[])
{
	for (int i = 0; i < MAX_ALIVE_ENEMIES; i++)
	{
		unrender(tanks[i]);
	}
}

void renderBounds()
{
	// Console title name
	SetConsoleTitleA("Battle City");

	// Console buffer size
	system("mode con lines=62 cols=102");

	SetColor(Brown, Black);

	//Battlefield bounds
	WriteChar(FIELD_X - 2, FIELD_Y - 1, char(201));
	WriteChar(FIELD_WIDTH + 2, FIELD_Y - 1, char(187));
	WriteChar(FIELD_X - 2, FIELD_HEIGHT + 1, char(200));
	WriteChar(FIELD_WIDTH + 2, FIELD_HEIGHT + 1, char(188));
	for (int x = FIELD_X - 1; x < FIELD_WIDTH + 2; x++)
	{
		WriteChar(x, FIELD_Y - 1, char(205));
		WriteChar(x, FIELD_HEIGHT + 1, char(205));
	}
	for (int y = FIELD_Y; y <= FIELD_HEIGHT; y++)
	{
		WriteChar(FIELD_X - 2, y, char(186));
		WriteChar(FIELD_WIDTH + 2, y, char(186));
	}

	//Counter bounds
	SetColor(Brown, Black);
	WriteChar(FIELD_X - 2, 28, char(185));
	WriteChar(FIELD_X - 2, 35, char(185));
	WriteChar(FIELD_X - 2, 42, char(185));
	for (int x = 0; x < FIELD_X - 2; x++)
	{
		SetColor(Brown, Black);
		WriteChar(x, 28, char(205));
		cout << "\n\n"
				"   D\n"
				" A O\n"
				" I W\n"
				"   N\n";
		SetColor(Brown, Black);
		WriteChar(x, 35, char(205));
		cout << "\n"
				" S\n"
				" H L\n"
				" I E\n"
				" E F\n"
				" L T\n"
				" D\n";
		WriteChar(x, 42, char(205));
		SetColor(LightGray, Black);
	}
}

void renderGameName(Letter letter)
{
	ShowCursor(false);

	SetColor(Brown, Black);

	for (int x = 0; x < CHARS_SIZE; x++)
	{
		for (int y = 0; y < CHARS_SIZE; y++)
		{
			WriteChar(x + letter.x, y + letter.y, letterSprites[letter.letterNumber][y][x]);
		}
		Sleep(100);
	}
	SetColor(LightGray, Black);
}

void renderCounter(Counter counter)
{
	for (int x = 0; x < COUNTER_DIMENTIONS; x++)
	{
		for (int y = 0; y < COUNTER_DIMENTIONS; y++)
		{
			WriteChar(x + counter.x1, y + counter.y, counterSprites[counter.digitNumber1][y][x]);
			WriteChar(x + counter.x2, y + counter.y, counterSprites[counter.digitNumber2][y][x]);
		}
	}
}