// Internal Imports
#include "Basic Components/BasicSolenoid.h"

BasicSolenoid::BasicSolenoid() {
  isLocked = true;
  pinMode(SOLENOID_PIN, OUTPUT);
  lastUnlocked = millis() - UNLOCK_TIMEOUT;
}

void BasicSolenoid::lockPanel() {
  digitalWrite(SOLENOID_PIN, LOW);
  isLocked = true;
}

void BasicSolenoid::unlockPanel() {
  digitalWrite(SOLENOID_PIN, HIGH);
  isLocked = false;
}

void BasicSolenoid::setState(bool isLocked) {
  if (isLocked) {
    lockPanel();
  }
  else {
    unlockPanel();
  }
}

bool BasicSolenoid::getState() {
  return isLocked;
}