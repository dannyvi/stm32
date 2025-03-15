#include "simple_display.h"
#include "led_via_ir.h"

int irState = LOW; // 红外传感器状态

void setupIR() {
    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW); 
    pinMode(IR_SENSOR, INPUT_PULLUP); 
    attachInterrupt(digitalPinToInterrupt(IR_SENSOR), handleIRInterrupt, CHANGE); // 设置中断
}

void handleIRInterrupt() { irState = digitalRead(IR_SENSOR); }

void loopIR() {
    if (irState == LOW) { // 检测到物体
        digitalWrite(LED_BLUE, HIGH); // Turn on the blue LED
        display.println("No Object");
    } else {
        digitalWrite(LED_BLUE, LOW); // Turn off the blue LED
        display.println("Detected");
    }
}