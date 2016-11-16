#include "RenderConsole.h"
#include "ConsoleLib.h"
#include "Sprites.h"

; void render(Tank tank)
{
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

void renderBounds()
{
	// Console title name
	SetConsoleTitleA("Battle City");

	// Console buffer size
	system("mode con lines=62 cols=102");

	ShowCursor(false);

	WriteChar(FIELD_X, FIELD_Y, char(201));
	WriteChar(FIELD_WIDTH, FIELD_Y, char(187));
	WriteChar(FIELD_X, FIELD_HEIGHT, char(200));
	WriteChar(FIELD_WIDTH, FIELD_HEIGHT, char(188));
	for (int x = FIELD_X + 1; x < FIELD_WIDTH; x++)
	{
		WriteChar(x, FIELD_Y, char(205));
		WriteChar(x, FIELD_HEIGHT, char(205));
	}
	for (int y = FIELD_Y + 1; y <= FIELD_HEIGHT - 1; y++)
	{
		WriteChar(FIELD_X, y, char(186));
		WriteChar(FIELD_WIDTH, y, char (186));
	}
}

void render(Tank tanks[])
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		render(tanks[i]);
	}
}

void unrender(Tank tanks[])
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		unrender(tanks[i]);
	}
}

void renderIntro()
{
	
}
