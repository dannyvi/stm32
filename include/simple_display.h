#ifndef SIMPLE_DISPLAY_H
#define SIMPLE_DISPLAY_H
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // OLED_RESET 是由硬件引脚控制的，如果没有可以设置为 -1

extern Adafruit_SSD1306 display;
void setupDisplay();

#endif