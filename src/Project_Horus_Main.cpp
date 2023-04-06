// Internal Imports
#include "Project_Horus_Main.h"

void serialEvent() {
  // Packet Update
}

void setup() {
  // Begin serial communicaton
  Serial.begin(SERIAL_BAUDRATE);
  // Wait for serial communication to be established
  while (!Serial) {delay(10);}

  fan = new BasicFan();
  solenoid = new BasicSolenoid();
  leds = new HorusLeds();
  motors = new HorusMotors();
  communication = new HorusCommunication(); // Unfinished
};

void loop() {

};
