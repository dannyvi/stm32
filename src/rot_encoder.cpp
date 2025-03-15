#include "rot_encoder.h"
#include "simple_display.h"

volatile int count = 0;                       // 计数变量
volatile unsigned long lastInterruptTime = 0; // 上次中断触发时间（用于去抖动）


void setupRotEncoder() {
    pinMode(INPUT_A, INPUT_PULLUP); // 设置引脚为输入，使用内部上拉电阻
    pinMode(INPUT_B, INPUT_PULLUP); // 设置引脚为输入，使用内部上拉电阻
    attachInterrupt(digitalPinToInterrupt(INPUT_A), updateEncoder, CHANGE);
}

void updateEncoder() {
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTime > 10) { // 去抖动：忽略5ms内的重复触发
        lastInterruptTime = currentTime;

        // 检查编码器的方向
        if (digitalRead(INPUT_A) == digitalRead(INPUT_B)) {
            count++; // 顺时针旋转
        } else {
            count--; // 逆时针旋转
        }
    }
}

void loopRotEncoder() {
    display.printf("Encoder Count: %d\n", count);
}