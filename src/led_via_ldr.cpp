#include <Arduino.h>
#include "led_via_ldr.h"
#include "simple_display.h"

int ldrValue = 1500;

void setupLedLDR() {
    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);
}

void ledLDRControl() {
    

  ldrValue = analogRead(LDR_PIN);
  display.print("LDR Value: ");
  display.println(ldrValue);


  if (ldrValue < 640) {            // - 当光线强度低于某个阈值（可根据需要调整）
    digitalWrite(LED_GREEN, HIGH); // 开启 LED2
    display.println("LED_GREEN: ON");
  } else {
    digitalWrite(LED_GREEN, LOW); // 关闭 LED2
    display.println("LED_GREEN: OFF");
  }

}