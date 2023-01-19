#include "config.h"

unsigned long lastUnlocked;

void solenoidSetup() {
  pinMode(SOLENOID_PIN, OUTPUT);
  lastUnlocked = millis() - 1000*60*2;
}

void lockPanel() {
  digitalWrite(SOLENOID_PIN, LOW);
}

void unlockPanel() {
  // Need to make sure everything else is off
  if (clearLEDs() && pillarsDecend() && lastUnlocked + 1000*60*2 <= millis()) {
    lastUnlocked = millis();
    while (lastUnlocked + 20000 >= millis() && isLocked == 0){
      packetUpdate();
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