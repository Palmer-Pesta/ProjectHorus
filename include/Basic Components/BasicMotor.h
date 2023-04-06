#pragma once
// External Imports
#include <Arduino.h>
#include <Stepper.h>
// Internal Imports
#include "Config.h"

class BasicMotor {
  private:
    Stepper* stepperMotor;

    int lowerLimitPin;

    int upperLimitPin;

    bool getLowerLimit();

    bool getUpperLimit();

  public:
    BasicMotor(int moterPin1, int motorPin2, int motorPin3, int motorPin4, int limitSwitchUpper, int limitSwitchLower);

    bool enabled;

    bool customStep(int amountOfRotation);

    void ascend();

    void descend();

    void disable();

    void enable();
};
