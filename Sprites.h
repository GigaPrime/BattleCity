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

#endif // !__SPRITES_H__
