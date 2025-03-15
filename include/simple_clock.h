#ifndef SIMPLE_CLOCK_H
#define SIMPLE_CLOCK_H

#include <SimpleTimer.h>

#define TIMER_INTERVAL_MS 1000

extern SimpleTimer clock_timer;
extern int timer_count;

void setupClock();
void loopClock();
void displayClock();

#endif