// Internal Imports
#include "Basic Components\BasicMotor.h"

BasicMotor::BasicMotor(int moterPin1, int motorPin2, int motorPin3, int motorPin4) {
  // Setup Limit Switches
  pinMode(WEST_LIMIT_SWITCH_UPPER, INPUT);
  stepperMotor = new Stepper(STEPS_PER_REVOLUTION, moterPin1, motorPin2, motorPin3, motorPin4); 

  // Setup Motor Speeds
  stepperMotor->setSpeed(BASE_MOTOR_SPEED);
}
