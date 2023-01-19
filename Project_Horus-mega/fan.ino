#include "config.h"
int current_fan_speed;

void fanSetup() {
  pinMode(FAN_CONTROL_PIN, OUTPUT);
  setPwmSpeed(0);
}

// @param int power from 0-100
void setPwmSpeed(int power) {
  analogWrite(FAN_CONTROL_PIN, power / 100 * 255);
  current_fan_speed = power / 100 * 255;
}

int getPwmSpeed() {
  return current_fan_speed;
}
