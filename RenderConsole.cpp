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
