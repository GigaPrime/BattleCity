#include <Windows.h>
#include <Conio.h>
#include "Round.h"
#include "Tank.h"
#include "Collisions.h"
#include "Constants.h"
#include "BattleCity.h"
#include "RenderConsole.h"

Tank player, prevPlayer;


void runBattle()
{
	COORD coord = { 0, 0 };
	player = newTank(coord, RIGHT);

	while (true)
	{
		handlePlayerInput();
		handleAiInput();
		render();
		Sleep(MAIN_LOOP_SLEEP);
	}
}

void handlePlayerInput()
{

}

void handleAiInput()
{

}

void render()
{
	unrender(prevPlayer);
	render(player);
}
