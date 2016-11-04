#ifndef __ROUND_H__
#define __ROUND_H__

struct Round
{
	double x;
	double y;
	bool isActive;
	int direction;
};


void handleRound();
void renderRound();
Round chageRoundState(Round round);
bool roundCollision(Round round);
Round newRound();

#endif // !__ROUND_H__
