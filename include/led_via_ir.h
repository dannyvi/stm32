#ifndef LED_VIA_IR_H
#define LED_VIA_IR_H
#include <Arduino.h>

#define LED_BLUE PB14 // 这是等在板子上的引脚信息
#define IR_SENSOR PA12

void setupIR();
void handleIRInterrupt();
void loopIR();

#endif