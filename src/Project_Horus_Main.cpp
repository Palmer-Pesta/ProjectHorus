// Internal Imports
#include "Project_Horus_Main.h"

void serialEvent() {
  communication.packetUpdate();
}

<<<<<<< HEAD
void ledProcessor() {
  if (communication.kitchen_motion || communication.rice_cooker || communication.toaster || communication.air_fryer) { 
    leds.autoWestLeds.setRed(255);
    leds.autoWestLeds.setGreen(0);
    leds.autoWestLeds.setBlue(0);
    leds.autoWestLeds.setIsOn(true);
    leds.setWest();
  }
  else {
    leds.turnOffWest();
  }

  if (communication.bedroom_motion || communication.computer) {
    leds.autoEastLeds.setRed(67);
    leds.autoEastLeds.setGreen(0);
    leds.autoEastLeds.setBlue(112);
    leds.autoEastLeds.setIsOn(true);
    leds.setEast();
  }
  else {
    leds.turnOffEast();
  }

  if (communication.tv) { // TODO: Add Livingroom Motion
    leds.autoNorthLeds.setRed(0);
    leds.autoNorthLeds.setGreen(255);
    leds.autoNorthLeds.setBlue(0);
    leds.autoNorthLeds.setIsOn(true);
    leds.setNorth();
  }
  else {
    leds.turnOffNorth();
  }

  if (communication.bathroom_motion) {
    leds.autoSouthLeds.setRed(0);
    leds.autoSouthLeds.setGreen(0);
    leds.autoSouthLeds.setBlue(255);
    leds.autoSouthLeds.setIsOn(true);
    leds.setSouth();
  }
  else if (communication.shower) {
    leds.autoSouthLeds.setRed(0);
    leds.autoSouthLeds.setGreen(100);
    leds.autoSouthLeds.setBlue(100);
    leds.autoSouthLeds.setIsOn(true);
    leds.setSouth();
  }
  else {
    leds.turnOffSouth();
  }

  if (communication.isHome && !communication.in_bed) {
    leds.autoTopLeds.setRed(255);
    leds.autoTopLeds.setGreen(255);
    leds.autoTopLeds.setBlue(255);
    leds.autoTopLeds.setIsOn(true);
    leds.setTop();
  }
  else {
    leds.turnOffTop();
  }
}

=======
>>>>>>> e2fadc65a1589b95a0f02126aba38a27cb824e47
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
