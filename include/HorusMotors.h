#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"
#include "Basic Components\BasicMotor.h"

class HorusMotors {      
  private:
    BasicMotor* westMotor;

    BasicMotor* eastMotor;

    BasicMotor* northMotor;

    BasicMotor* southMotor;

    BasicMotor* topMotor;

    BasicMotor* getSection(String section);

  public:
    HorusMotors();

    void pillarAscend(String section);

    void pillarDescend(String section);

    void customStep(String section, int stepAmount);
};