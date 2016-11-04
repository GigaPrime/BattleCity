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



int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				cout << tankSprites[i][x][y];
			}
			cout << std::endl;
		}
		cout << endl << endl;
	}
	return 0;
}

void render()
{
	
}

