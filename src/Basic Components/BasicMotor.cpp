// Internal Imports
#include "Basic Components\BasicMotor.h"

BasicMotor::BasicMotor(int moterPin1, int motorPin2, int motorPin3, int motorPin4, int limitSwitchUpper, int limitSwitchLower) {
  pinMode(WEST_LIMIT_SWITCH_UPPER, INPUT);
  stepperMotor = new Stepper(STEPS_PER_REVOLUTION, moterPin1, motorPin2, motorPin3, motorPin4); 
  stepperMotor->setSpeed(BASE_MOTOR_SPEED);
  enabled = true;
  lowerLimitPin = limitSwitchLower;
  upperLimitPin = limitSwitchUpper;
}

bool BasicMotor::getLowerLimit() {
  return digitalRead(lowerLimitPin);
}

bool BasicMotor::getUpperLimit() {
  return digitalRead(upperLimitPin);
}

void BasicMotor::disable() {
  enabled = false;
}

void BasicMotor::enable() {
  enabled = true;
}

bool BasicMotor::customStep(int amountOfRotation) {
  if (enabled) {
    if ((amountOfRotation <= 0 && !getLowerLimit()) || (amountOfRotation >= 0 && !getUpperLimit())) {
      int sign = amountOfRotation/abs(amountOfRotation);
      for(int i=0; i<abs(amountOfRotation); i++) {
        if (!getLowerLimit()) {
          stepperMotor->step(1*sign);
        }
      }
      return false;
    }
    else {
      return true;
    }
  }
}

void BasicMotor::ascend() {
  if(enabled) {
    while(!getUpperLimit()) {
      stepperMotor->step(1);
    }
  }
}

void BasicMotor::descend() {
  if(enabled) {
    while(!getLowerLimit()) {
      stepperMotor->step(-1);
    }
  }
}


