#ifndef __ROUND_H__
#define __ROUND_H__

struct Round
{
	double x;
	double y;
	bool isActive;
	int direction;
};

Round chageRoundState(Round round);
void killRound(Round& round);

#endif // !__ROUND_H__
