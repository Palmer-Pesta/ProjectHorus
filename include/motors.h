#pragma once
// External Imports
#include <Arduino.h>
#include <Stepper.h>
// Internal Imports
#include "Config.h"

class HorusMotor {
  private:
    Stepper* stepperW = new Stepper(STEPS_PER_REVOLUTION, MOTOR1_1, MOTOR1_2, MOTOR1_3, MOTOR1_4); // Motor 1
    Stepper* stepperE = new Stepper(STEPS_PER_REVOLUTION, MOTOR2_1, MOTOR2_2, MOTOR2_3, MOTOR2_4); // Motor 2
    Stepper* stepperN = new Stepper(STEPS_PER_REVOLUTION, MOTOR3_1, MOTOR3_2, MOTOR3_3, MOTOR3_4); // Motor 3
    Stepper* stepperS = new Stepper(STEPS_PER_REVOLUTION, MOTOR4_1, MOTOR4_2, MOTOR4_3, MOTOR4_4); // Motor 4
    Stepper* stepperT = new Stepper(STEPS_PER_REVOLUTION, MOTOR5_1, MOTOR5_2, MOTOR5_3, MOTOR5_4); // Motor 5

  public:
    void motorSetup();

    bool pillarsDecend();

    void eastPillarPeak();

    void eastPillarTrough();

    void northPillarPeak();

    void northPillarTrough();

    void westPillarPeak();

    void westPillarTrough();

    void southPillarPeak();

    void southPillarTrough();

    void topPillarPeak();

    void topPillarTrough();
};
