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
  
  HorusMotor* motors = new HorusMotor();
  HorusFan* fan = new HorusFan();
  HorusLeds* leds = new HorusLeds();
  HorusSolenoid* solenoid = new HorusSolenoid();

  communication.livelinessSetup();
};

void loop() {
  solenoid.lockProcessor(communication.isLocked);
  leds.ledProcessor(&communication);
  communication.livelinessProbe();
};
