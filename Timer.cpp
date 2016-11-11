#include "Timer.h"
#include "Constants.h"

Timer newTimer(double seconds)
{
	Timer newTimer;
	newTimer.isAlive = true;
	newTimer.counter = int(FPS * seconds);
	return newTimer;
}
