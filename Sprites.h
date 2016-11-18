#include "Constants.h"

#ifndef __SPRITES_H__
#define	__SPRITES_H__

char tankSprites[TOTAL_DIRECTIONS][TANK_HEIGHT][TANK_WIDTH]
{
	{
		{ CH, CH, CH, CH, CH },
		{ SP, BD, GH, GH, SP },
		{ CH, CH, CH, CH, CH }
	},

	{
		{ CV, SP, SP, SP, CV },
		{ CV, BD, BD, BD, CV },
		{ CV, SP, GV, SP, CV }
	},

	{
		{ CH, CH, CH, CH, CH },
		{ SP, GH, GH, BD, SP },
		{ CH, CH, CH, CH, CH }
	},

	{
		{ CV, SP, GV, SP, CV },
		{ CV, BD, BD, BD, CV },
		{ CV, SP, SP, SP, CV }
	}

};

char letterSprites[TOTAL_CHARS][CHARS_SIZE][CHARS_SIZE]
{
	{
		//B
		{ BF, BB, BF, BB, BF, BB, BF, BB, BF, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, BB, BF, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, BF, BB, SP, SP },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, BF, BB, BF, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, BF, BB, BF, BB },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, SP }
	},

	{
		//A
		{ SP, SP, SP, SP, BF, BB, BF, BB, BF, BB, BF, BB },
		{ SP, SP, SP, BF, BB, BF, SP, SP, SP, BF, BB, BF },
		{ SP, SP, BF, BB, BF, SP, SP, SP, SP, BB, BF, BB },
		{ SP, SP, BB, BF, BB, SP, SP, SP, SP, BF, BB, BF },
		{ SP, BB, BF, BB, SP, SP, SP, SP, SP, BB, BF, BB },
		{ SP, BF, BB, BF, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF }
	},

	{
		//T
		{ BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, BB, BF },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP }
	},

	{
		//L
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, BF, BB },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF }
	},

	{
		//E
		{ BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, BF, BB },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF }
	},

	{
		//C
		{ SP, SP, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ SP, BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF },
		{ SP, BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, SP, SP, SP },
		{ SP, BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF },
		{ SP, BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB },
		{ SP, SP, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF }
	},

	{
		//I
		{ BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BB, BF, BB, SP, SP, SP, SP, SP },
		{ SP, SP, SP, SP, BF, BB, BF, SP, SP, SP, SP, SP },
		{ BB, BF, BB, BF, BB, BF, BB, BF, BB, BF, BB, BF }
	},

	{
		//Y
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, BF, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ SP, BB, BF, BB, SP, SP, SP, SP, SP, BB, BF, BB },
		{ SP, SP, BB, BF, SP, SP, SP, SP, SP, BF, BB, BF },
		{ SP, SP, SP, BB, BF, BB, BF, BB, BF, BB, BF, BB },
		{ SP, SP, SP, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ SP, SP, SP, SP, SP, SP, SP, SP, SP, BB, BF, BB },
		{ BB, BF, SP, SP, SP, SP, SP, SP, SP, BF, BB, BF },
		{ BF, BB, SP, SP, SP, SP, SP, SP, BF, BB, BF, SP },
		{ SP, BF, BB, BF, BB, BF, BB, BF, BB, BF, SP, SP }
	},
};

char counterSprites[COUNTER_NUMBER][COUNTER_DIMENTIONS][COUNTER_DIMENTIONS]
{
	{
		// 1
		{ SP, SP, SP },
		{ SP, SP, VS },
		{ SP, SP, VS }
	},

	{
		//2
		{ SP, HS, SP },
		{ SP, HS, VS },
		{ VS, HS, SP }
	},

	{
		//3
		{ SP, HS, SP },
		{ SP, HS, VS },
		{ SP, HS, VS }
	},

	{
		//4
		{ SP, SP, SP },
		{ VS, HS, VS },
		{ SP, SP, VS }
	},

	{
		//5
		{ SP, HS, SP },
		{ VS, HS, SP },
		{ SP, HS, VS }
	},

	{
		//6
		{ SP, HS, SP },
		{ VS, HS, SP },
		{ VS, HS, VS }
	},

	{
		//7
		{ SP, HS, SP },
		{ SP, SP, VS },
		{ SP, SP, VS }
	},

	{
		//8
		{ SP, HS, SP },
		{ VS, HS, VS },
		{ VS, HS, VS }
	},

	{
		//9
		{ SP, HS, SP },
		{ VS, HS, VS },
		{ SP, HS, VS }
	},

	{
		//0
		{ SP, HS, SP },
		{ VS, SP, VS },
		{ VS, HS, VS }
	},
};

#endif // !__SPRITES_H__
