#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "config.h"

class HorusFan {      
  private:
    int current_fan_speed; 
  public:        
       
    void fanSetup();

    void setPwmSpeed(int power);

    int getPwmSpeed();
};
