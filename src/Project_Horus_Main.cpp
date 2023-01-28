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
};

void loop() {
  //communication.livelinessProbe();
  if((millis() % 500) == 0) {
    leds.updateLEDs();
  }
};

void serialEvent() {
  communication.packetUpdate();
}
