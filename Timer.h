#ifndef __TIMER_H__
#define __TIMER_H__

struct Timer
{
	bool isAlive;
	int counter;
};

Timer newTimer(double seconds);

#endif // !__TIMER_H__
