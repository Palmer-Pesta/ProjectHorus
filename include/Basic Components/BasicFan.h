#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class BasicFan {      
  private:
    int current_fan_speed; 
    
  public:        
    BasicFan();
    
    void setPwmSpeed(int power);

    int getPwmSpeed();
};
