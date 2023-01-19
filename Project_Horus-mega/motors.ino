#include "config.h"
#include <Stepper.h>

Stepper stepperW(stepsPerRevolution, MOTOR1_1, MOTOR1_2, MOTOR1_3, MOTOR1_4); // Motor 1
Stepper stepperE(stepsPerRevolution, MOTOR2_1, MOTOR2_2, MOTOR2_3, MOTOR2_4); // Motor 2
Stepper stepperN(stepsPerRevolution, MOTOR3_1, MOTOR3_2, MOTOR3_3, MOTOR3_4); // Motor 3
Stepper stepperS(stepsPerRevolution, MOTOR4_1, MOTOR4_2, MOTOR4_3, MOTOR4_4); // Motor 4
Stepper stepperT(stepsPerRevolution, MOTOR5_1, MOTOR5_2, MOTOR5_3, MOTOR5_4); // Motor 5

void motorSetup() {
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
  stepperW.setSpeed(BASE_MOTOR_SPEED);
  stepperE.setSpeed(BASE_MOTOR_SPEED);
  stepperN.setSpeed(BASE_MOTOR_SPEED);
  stepperS.setSpeed(BASE_MOTOR_SPEED);
  stepperT.setSpeed(BASE_MOTOR_SPEED);
}

bool pillarsDecend() {
  return true;
}

void eastPillarPeak() {
  while (digitalRead(EAST_LIMIT_SWITCH_UPPER)) {
    stepperE.step(1); // Make negative to go the counterclockwise
  }
}

void eastPillarTrough() {
  while (digitalRead(EAST_LIMIT_SWITCH_LOWER)) {
    stepperE.step(1); // Make negative to go the counterclockwise
  }
}

void northPillarPeak() {
  while (digitalRead(NORTH_LIMIT_SWITCH_UPPER)) {
    stepperN.step(1); // Make negative to go the counterclockwise
  }
}

void northPillarTrough() {
  while (digitalRead(NORTH_LIMIT_SWITCH_LOWER)) {
    stepperN.step(1); // Make negative to go the counterclockwise
  }
}

void westPillarPeak() {
  while (digitalRead(WEST_LIMIT_SWITCH_UPPER)) {
    stepperW.step(1); // Make negative to go the counterclockwise
  }
}

void westPillarTrough() {
  while (digitalRead(WEST_LIMIT_SWITCH_LOWER)) {
    stepperW.step(1); // Make negative to go the counterclockwise
  }
}

void southPillarPeak() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_UPPER)) {
    stepperS.step(1); // Make negative to go the counterclockwise
  }
}

void southPillarTrough() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_LOWER)) {
    stepperS.step(1); // Make negative to go the counterclockwise
  }
}

void topPillarPeak() {
  while (digitalRead(TOP_LIMIT_SWITCH_UPPER)) {
    stepperT.step(1); // Make negative to go the counterclockwise
  }
}

void topPillarTrough() {
  while (digitalRead(TOP_LIMIT_SWITCH_LOWER)) {
    stepperT.step(1); // Make negative to go the counterclockwise
  }
}