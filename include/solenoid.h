#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class HorusSolenoid {      
  private:
    unsigned long lastUnlocked;
    
    bool isLocked;

  public:
    void solenoidSetup();

    void lockPanel();

    void unlockPanel();

    void setState(bool isLocked);

    bool getState();
};
