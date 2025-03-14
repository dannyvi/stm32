#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#define LED_RED PB12 // 这是等在板子上的引脚信息
#define LED_GREEN PB13
#define LED_BLUE PB14
#define LED_YELLOW PB15
#define BUTTON PB11
#define LDR_PIN PB1

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // OLED_RESET 是由硬件引脚控制的，如果没有可以设置为 -1

#define IR_SENSOR PA12
#define INPUT_A PA9
#define INPUT_B PA10

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buttonState; // 按钮状态变量
int lastButtonState = LOW;
int ldrValue = 1500;
int irState = HIGH; // 红外传感器状态

volatile int count = 0;                       // 计数变量
volatile unsigned long lastInterruptTime = 0; // 上次中断触发时间（用于去抖动）

void handleIRInterrupt() {
  // irTriggered = true; // 设置红外传感器触发标志
  irState = digitalRead(IR_SENSOR);
  // irTriggered = false; // 清除标志
}

// 中断服务程序
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

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(IR_SENSOR, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(IR_SENSOR), handleIRInterrupt, CHANGE);

  pinMode(INPUT_A, INPUT_PULLUP); // 设置引脚为输入，使用内部上拉电阻
  pinMode(INPUT_B, INPUT_PULLUP); // 设置引脚为输入，使用内部上拉电阻
  attachInterrupt(digitalPinToInterrupt(INPUT_A), updateEncoder, CHANGE);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  Serial.begin(9600);                        // Initialize serial communication
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 初始化 OLED，地址通常是 0x3C
  display.clearDisplay();                    // 清空显示器
  display.setTextSize(1);                    // 设置文本大小
  display.setTextColor(SSD1306_WHITE);       // 设置文本颜色
  display.setCursor(0, 0);                   // 设置光标位置
  display.println("OLED Initialized!");      // 打印初始化信息
  display.display();                         // 刷新 OLED 显示
}

void loop() {

  display.clearDisplay();  // 清空屏幕
  display.setCursor(0, 0); // 重置光标位置

  Serial.print("Switch Value: ");
  int buttonState = digitalRead(BUTTON);
  display.print("Switch Value: ");
  display.println(buttonState);
  if (buttonState == HIGH && lastButtonState == LOW) {
    digitalWrite(LED_RED, !digitalRead(LED_RED));
    // digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
    display.println("Button Pressed! LED_Toggled");
  }
  display.print("LED_RED: ");
  display.println(digitalRead(LED_RED) ? "OFF" : "ON");

  lastButtonState = buttonState;

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

  display.printf("IR: %d ", irState);
  if (irState == LOW) { // 检测到物体
    digitalWrite(LED_BLUE, HIGH);
    display.println("No Object");
    Serial.println("No Object Detected by IR Sensor");
  } else {
    digitalWrite(LED_BLUE, LOW);
    display.println("Detected");
    Serial.println("Object Detected by IR Sensor");
  }

  display.printf("Encoder Count: %d", count);
  Serial.print("Encoder Count: ");
  Serial.println(count);

  display.display(); // 刷新 OLED 显示

  delay(100);
}
