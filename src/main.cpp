#include <Arduino.h>

#define LED_RED PB5 // 这是等在板子上的引脚信息
#define LED_GREEN PA10
#define BUTTON PB11


int buttonState;           // 按钮状态变量
int lastButtonState = LOW;

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON, INPUT);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    Serial.begin(9600); // Initialize serial communication
}

void loop() {

    Serial.print("Switch Value: ");
    int buttonState = digitalRead(BUTTON);
    if (buttonState == HIGH && lastButtonState == LOW) {
        digitalWrite(LED_RED, !digitalRead(LED_RED));
        digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
        Serial.println("LED_GREEN is ON, LED_RED is OFF");
    }
    lastButtonState = buttonState;
    delay(100);
}
