// Internal Imports
#include "Project_Horus_Main.h"

void serialEvent() {
  communication.packetUpdate();
}

void setup() {
  // Begin serial communicaton
  Serial.begin(SERIAL_BAUDRATE);
  // Wait for serial communication to be established
  while (!Serial) {delay(10);}

  // Run the setup
  communication.livelinessSetup();
  motor.motorSetup();
  fan.fanSetup();
  leds.ledSetup();
  solenoid.solenoidSetup();
};

void loop() {
  solenoid.lockProcessor(communication.isLocked);
  leds.ledProcessor(&communication);
  communication.livelinessProbe();
};
