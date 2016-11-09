#include "RenderConsole.h"
#include "ConsoleLib.h"
#include "Sprites.h"

void render(Tank tank)
{
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
	WriteChar(round.x, round.y, '*');
}

void unrender(Round round)
{
	WriteChar(round.x, round.y, ' ');
}

void renderBounds()
{
	ShowCursor(false);

	for (int x = FIELD_X; x <= FIELD_WIDTH; x++)
	{
		WriteChar(x, FIELD_Y, 'X');
		WriteChar(x, FIELD_HEIGHT, 'X');
	}
	for (int y = FIELD_Y; y <= FIELD_HEIGHT; y++)
	{
		WriteChar(FIELD_X, y, 'X');
		WriteChar(FIELD_WIDTH, y, 'X');
	}
}
