#include "Tank.h"
#include "Constants.h"

#ifndef __SPRITES_H__
#define	__SPRITES_H__

char tankSprites[4][3][5]
{
	{
		{ CH, CH, CH, CH, CH },
		{ SP, BD, GH, GH, SP },
		{ CH, CH, CH, CH, CH }
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
	},

	{
		{ CV, SP, SP, SP, CV },
		{ CV, BD, BD, BD, CV },
		{ CV, SP, GV, SP, CV }
	},
};

#endif // !__SPRITES_H__
