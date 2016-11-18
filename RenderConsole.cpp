#include "RenderConsole.h"
#include "ConsoleLib.h"
#include "Sprites.h"

; void render(Tank tank)
{
	render(tank.round);

	if (tank.isAlive == false)
	{
		return;
	}
	for (int x = 0; x < TANK_WIDTH; x++)
	{
		for (int y = 0; y < TANK_HEIGHT; y++)
		{
			WriteChar(x + tank.x, y + tank.y, tankSprites[tank.direction][y][x]);
		}
	}
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
}

void renderGameName(Letter letter)
{
	ShowCursor(false);

	for (int x = 0; x < CHARS_SIZE; x++)
	{
		for (int y = 0; y < CHARS_SIZE; y++)
		{
			WriteChar(x + letter.x, y + letter.y, letterSprites[letter.letterNumber][y][x]);
		}
		Sleep(100);
	}
}

void renderCounter(Counter counter)
{
	for (int x = 0; x < COUNTER_DIMENTIONS; x++)
	{
		for (int y = 0; y < COUNTER_DIMENTIONS; y++)
		{
			WriteChar(x + counter.x, y + counter.y, counterSprites[counter.digitNumber - 1][y][x]);
		}
	}
}