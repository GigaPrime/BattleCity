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

#endif // !__SPRITES_H__
