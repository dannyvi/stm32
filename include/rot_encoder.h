#ifndef ROT_ENCODER_H
#define ROT_ENCODER_H
#include <Arduino.h>
#include <Wire.h>

#define INPUT_A PA9
#define INPUT_B PA10

void setupRotEncoder();

void updateEncoder();

void loopRotEncoder();

#endif