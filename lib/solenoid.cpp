// External Imports
#include <Arduino.h>
// Internal Imports
#include "../config.h"
#include "communication.cpp"
#include "motors.cpp"

class HorusSolenoid {      
  private:
    unsigned long lastUnlocked;
    bool isLocked;
  public:
    HorusLeds* leds = new HorusLeds();
    HorusCommunication* communication = new HorusCommunication();
    HorusMotor* motor = new HorusMotor();

    void solenoidSetup() {
      pinMode(SOLENOID_PIN, OUTPUT);
      lastUnlocked = millis() - UNLOCK_TIMEOUT;
    }

    void lockPanel() {
      digitalWrite(SOLENOID_PIN, LOW);
    }

    void unlockPanel() {
      // Need to make sure everything else is off
      if (leds->clearLEDs() && motor->pillarsDecend() && lastUnlocked + UNLOCK_TIMEOUT <= millis()) {
        lastUnlocked = millis();
        while (lastUnlocked + 20000 >= millis() && isLocked == 0){
          communication->packetUpdate();
          digitalWrite(SOLENOID_PIN, HIGH);
        }
      }
      lockPanel();
    }

    void lockProcessor(bool isLocked) {
      if (isLocked == 1) {
        lockPanel();
      }
      else {
        unlockPanel();
      }
    }
};