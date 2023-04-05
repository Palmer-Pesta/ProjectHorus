#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class HorusFan {      
  private:
    int current_fan_speed; 
    
  public:        
    void fanSetup();
    
    void setPwmSpeed(int power);

    int getPwmSpeed();
};
