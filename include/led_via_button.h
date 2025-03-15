#ifndef LED_VIA_BUTTON_H
#define LED_VIA_BUTTON_H

#define LED_RED PB12 // 这是等在板子上的引脚信息
#define BUTTON PB11

void setupButtonLed();
void buttonLightControl();

#endif
