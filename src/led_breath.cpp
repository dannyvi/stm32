
#include <Wire.h>
#include <Arduino.h>
#include <SimpleTimer.h>
#include "led_breath.h"

#include <math.h> // Include math library for sine function
SimpleTimer timerPWM;

const int maxBrightness = 255;    // LED最大亮度
const float pi = 3.14159265;      // Pi value for sine calculations
int step = 0;                     // Current step in the sine wave
const int totalSteps = 100;       // Total steps for one breathing cycle

// 更新亮度的函数
void updateBrightness() {
    float angle = (2 * pi * step) / totalSteps; // Calculate the angle for the sine wave
    int brightness = (sin(angle) + 1) / 2 * maxBrightness; // Map sine wave (-1 to 1) to (0 to maxBrightness)
    analogWrite(LED_YELLOW, brightness); // 设置 LED 亮度

    step = (step + 1) % totalSteps; // Increment step and wrap around after one cycle
}

void setupYellowLed() {
    pinMode(LED_YELLOW, OUTPUT); // 设置 LED 引脚为输出
    analogWriteResolution(8); // 设置 PWM 分辨率为 8 位

    timerPWM.setInterval(20, updateBrightness); // 每20毫秒调用一次 updateBrightness
}