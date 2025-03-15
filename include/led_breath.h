#ifndef LED_BREATH_H
#define LED_BREATH_H

#include <SimpleTimer.h>

#define LED_YELLOW PA8

extern SimpleTimer timerPWM; // Declare timerPWM as an external variable

void setupYellowLed();
void updateBrightness();

#endif