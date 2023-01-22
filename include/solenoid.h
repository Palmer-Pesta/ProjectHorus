#pragma once
#include "config.h"

// #ifndef HorusSolenoid_H
// #define HorusSolenoid_H
class HorusSolenoid {      
  private:
    unsigned long lastUnlocked;
    bool isLocked;
  public:

    void solenoidSetup();

    void lockPanel();

    void unlockPanel();

    void lockProcessor(bool isLocked);
};
// #endif