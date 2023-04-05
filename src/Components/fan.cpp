// Internal Imports
#include "Fan.h"

           
void HorusFan::fanSetup() {
  pinMode(FAN_CONTROL_PIN, OUTPUT);
  setPwmSpeed(0);
}

// @param int power from 0-100
void HorusFan::setPwmSpeed(int power) {
  analogWrite(FAN_CONTROL_PIN, power / 100 * 255);
  current_fan_speed = power / 100 * 255;
}

int HorusFan::getPwmSpeed() {
  return current_fan_speed;
}
