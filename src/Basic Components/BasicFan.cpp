// Internal Imports
#include "Basic Components\BasicFan.h"

BasicFan::BasicFan() {
  pinMode(FAN_CONTROL_PIN, OUTPUT);
  setPwmSpeed(0);
}

// @param int power from 0-100
void BasicFan::setPwmSpeed(int power) {
  analogWrite(FAN_CONTROL_PIN, power / 100 * 255);
  current_fan_speed = power / 100 * 255;
}

int BasicFan::getPwmSpeed() {
  return current_fan_speed;
}
