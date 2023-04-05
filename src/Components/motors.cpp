// Internal Imports
#include "Motors.h"

void HorusMotor::motorSetup() {
  // Setup Limit Switches
  pinMode(WEST_LIMIT_SWITCH_UPPER, INPUT);
  pinMode(WEST_LIMIT_SWITCH_LOWER, INPUT);
  pinMode(EAST_LIMIT_SWITCH_UPPER, INPUT);
  pinMode(EAST_LIMIT_SWITCH_LOWER, INPUT);
  pinMode(NORTH_LIMIT_SWITCH_UPPER, INPUT);
  pinMode(NORTH_LIMIT_SWITCH_LOWER, INPUT);
  pinMode(SOUTH_LIMIT_SWITCH_UPPER, INPUT);
  pinMode(SOUTH_LIMIT_SWITCH_LOWER, INPUT);
  pinMode(TOP_LIMIT_SWITCH_UPPER, INPUT);
  pinMode(TOP_LIMIT_SWITCH_LOWER, INPUT);
  // Setup Motor Speeds
  stepperW->setSpeed(BASE_MOTOR_SPEED);
  stepperE->setSpeed(BASE_MOTOR_SPEED);
  stepperN->setSpeed(BASE_MOTOR_SPEED);
  stepperS->setSpeed(BASE_MOTOR_SPEED);
  stepperT->setSpeed(BASE_MOTOR_SPEED);
}

bool HorusMotor::pillarsDecend() {
  return true;
}

void HorusMotor::westPillarPeak() {
  while (digitalRead(WEST_LIMIT_SWITCH_UPPER)) {
    stepperW->step(1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::westPillarTrough() {
  while (digitalRead(WEST_LIMIT_SWITCH_LOWER)) {
    stepperW->step(-1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::eastPillarPeak() {
  while (digitalRead(EAST_LIMIT_SWITCH_UPPER)) {
    stepperE->step(1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::eastPillarTrough() {
  while (digitalRead(EAST_LIMIT_SWITCH_LOWER)) {
    stepperE->step(-1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::northPillarPeak() {
  while (digitalRead(NORTH_LIMIT_SWITCH_UPPER)) {
    stepperN->step(1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::northPillarTrough() {
  while (digitalRead(NORTH_LIMIT_SWITCH_LOWER)) {
    stepperN->step(-1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::southPillarPeak() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_UPPER)) {
    stepperS->step(1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::southPillarTrough() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_LOWER)) {
    stepperS->step(-1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::topPillarPeak() {
  while (digitalRead(TOP_LIMIT_SWITCH_UPPER)) {
    stepperT->step(1); // Make negative to go the counterclockwise
  }
}

void HorusMotor::topPillarTrough() {
  while (digitalRead(TOP_LIMIT_SWITCH_LOWER)) {
    stepperT->step(-1); // Make negative to go the counterclockwise
  }
}
