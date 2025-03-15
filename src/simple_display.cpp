#include <Wire.h>
#include <Arduino.h>

#include "simple_display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupDisplay() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 初始化 OLED，地址通常是 0x3C
    display.clearDisplay();                    // 清空显示器
    display.setTextSize(1);                    // 设置文本大小
    display.setTextColor(SSD1306_WHITE);       // 设置文本颜色
    display.setCursor(0, 0);                   // 设置光标位置
    display.println("OLED Initialized!");      // 打印初始化信息
    display.display();                         // 刷新 OLED 显示
}
