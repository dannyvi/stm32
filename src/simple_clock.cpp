
#include <Wire.h>
#include <Arduino.h>


#include "simple_clock.h"
#include "simple_display.h"

SimpleTimer clock_timer;
int timer_count;

// 定时器中断处理程序
void timerCallback() {
    timer_count++; // 每次定时器触发时增加计数
}

void setupClock() {
    clock_timer.setInterval(TIMER_INTERVAL_MS, timerCallback); // 每隔 1000ms 触发一次 timerCallback
  }


void loopClock() {
    clock_timer.run();
}

void displayClock() {
    display.printf("Timer: %d\n", timer_count);
}