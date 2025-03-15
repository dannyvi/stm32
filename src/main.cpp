#include <Wire.h>
#include <Arduino.h>
#include "simple_display.h"
#include "led_breath.h"
#include "simple_clock.h"
#include "led_via_button.h"
#include "led_via_ldr.h"
#include "led_via_ir.h"
#include "rot_encoder.h"




void setup() {
  setupYellowLed();
  setupDisplay(); // Initialize the OLED display
  setupClock();
  setupButtonLed(); // Initialize the button and LED
  setupLedLDR(); // Initialize the LDR and LED
  setupRotEncoder(); 
  setupIR(); // Initialize the IR sensor

  Serial.begin(9600);          // Initialize serial communication
                      // 刷新 OLED 显示
}

void loop() {

  display.clearDisplay();  // 清空屏幕
  display.setCursor(0, 0); // 重置光标位置

  timerPWM.run(); // Use the external timerPWM
  loopClock();
  displayClock();
  buttonLightControl(); // 控制 LED 灯的函数
  ledLDRControl(); // 控制 LDR 的函数
  loopRotEncoder(); // 控制旋转编码器的函数
  loopIR(); 

  display.display(); // 刷新 OLED 显示

  // delay(100);
}
