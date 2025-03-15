#include <Arduino.h>
#include "led_via_button.h"
#include "simple_display.h"


int buttonState; // 按钮状态变量
int lastButtonState = LOW;

void setupButtonLed() {
    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, LOW);
    pinMode(BUTTON, INPUT_PULLUP);
}

void buttonLightControl() {
    int buttonState = digitalRead(BUTTON);
    if (buttonState == HIGH && lastButtonState == LOW) {
        digitalWrite(LED_RED, !digitalRead(LED_RED));
        // digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW));
        // digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
    }
    lastButtonState = buttonState;
}