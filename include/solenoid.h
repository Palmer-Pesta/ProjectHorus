#pragma once
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
