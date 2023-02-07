// Internal Imports
#include "solenoid.h"

void HorusSolenoid::solenoidSetup() {
  pinMode(SOLENOID_PIN, OUTPUT);
  lastUnlocked = millis() - UNLOCK_TIMEOUT;
}

void HorusSolenoid::lockPanel() {
  digitalWrite(SOLENOID_PIN, LOW);
  isLocked = true;
}

void HorusSolenoid::unlockPanel() {
  digitalWrite(SOLENOID_PIN, HIGH);
  isLocked = false;
}

void HorusSolenoid::lockProcessor(bool isLocked) {
  if (isLocked == 1) {
    lockPanel();
  }
  else {
    unlockPanel();
  }
}

bool HorusSolenoid::getState() {
  return isLocked;
}