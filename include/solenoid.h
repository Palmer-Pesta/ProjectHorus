#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "config.h"

class HorusSolenoid {      
  private:
    unsigned long lastUnlocked;
    
    bool isLocked = true;

  public:
    void solenoidSetup();

    void lockPanel();

    void unlockPanel();

    void lockProcessor(bool isLocked);

    bool getState();
};
