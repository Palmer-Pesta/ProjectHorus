// External Imports
#include <Arduino.h>
// Internal Imports
#include "communication.h"
#include "fan.h"
#include "leds.h"
#include "motors.h"
#include "solenoid.h"
#include "config.h"

// Create Class Instantances
HorusCommunication communication;
HorusFan fan;
HorusLeds leds;
HorusMotor motor;
HorusSolenoid solenoid;

void serialEvent() {
  communication.packetUpdate();
}

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

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  while (!Serial) {delay(10);}
  communication.fan = &fan;
  communication.leds = &leds;
  communication.motor = &motor;
  communication.solenoid = &solenoid;

  communication.livelinessSetup();
  motor.motorSetup();
  fan.fanSetup();
  leds.ledSetup();
  solenoid.solenoidSetup();
  leds.updateLEDs();
};

void loop() {
  solenoid.lockProcessor(communication.isLocked);
  ledProcessor();
  communication.livelinessProbe();
};
