#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class BasicSolenoid {      
  private:
    unsigned long lastUnlocked;
    
    bool isLocked;

    void lockPanel();

    void unlockPanel();

  public:
    BasicSolenoid();

    void setState(bool isLocked);

    bool getState();
};
