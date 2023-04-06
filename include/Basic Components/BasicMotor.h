#pragma once
// External Imports
#include <Arduino.h>
#include <Stepper.h>
// Internal Imports
#include "Config.h"

class BasicMotor {
  private:
    Stepper* stepperMotor;

  public:
    BasicMotor(int moterPin1, int motorPin2, int motorPin3, int motorPin4);

};
