#include "Round.h"
#include "Constants.h"
using namespace std;

Round chageRoundState(Round round)
{
	double deltaH = ROUND_SPEED_H / FPS;
	double deltaV = ROUND_SPEED_V / FPS;

	switch (round.direction)
	{
	case RIGHT:
		round.x += deltaH;
		break;
	case DOWN:
		round.y += deltaV;
		break;
	case LEFT:
		round.x -= deltaH;
		break;
	case UP:
		round.y -= deltaV;
		break;
	}
	return round;
}
