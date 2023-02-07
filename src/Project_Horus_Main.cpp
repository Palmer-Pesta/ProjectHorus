// Internal Imports
#include "leds.h"
#include "communication.h"
#include "fan.h"
#include "motors.h"
#include "solenoid.h"
#include "config.h"

// Create Class Instantances
HorusCommunication communication;
HorusFan fan;
HorusLeds leds;
HorusMotor motor;
HorusSolenoid solenoid;

/*
 * Upon getting a serial event execute the packet update code
*/
void serialEvent() {
  communication.packetUpdate();
}

void setup() {
  // Begin serial communicaton
  Serial.begin(SERIAL_BAUDRATE);
  // Wait for serial communication to be established
  while (!Serial) {delay(10);}

  // Instantiate the components
  communication.fan = &fan;
  communication.leds = &leds;
  communication.motor = &motor;
  communication.solenoid = &solenoid;

  // Run the setup
  communication.livelinessSetup();
  motor.motorSetup();
  fan.fanSetup();
  leds.ledSetup();
  solenoid.solenoidSetup();
  leds.updateLEDs();
};

void loop() {
  solenoid.lockProcessor(communication.isLocked);
  leds.ledProcessor(&communication);
  communication.livelinessProbe();
};
