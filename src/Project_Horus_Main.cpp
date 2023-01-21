// External Imports
#include <Stepper.h>
#include <FastLED.h>
#include <HardwareSerial.h>
// Internal Imports
#include "../lib/solenoid.cpp"

HorusLeds* leds = new HorusLeds();
HorusSolenoid* solenoid = new HorusSolenoid();
HorusFan* fan = new HorusFan();
HorusCommunication* commmunication = new HorusCommunication();
HorusMotor* motor = new HorusMotor();

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  motor->motorSetup();
  leds->ledSetup();
  fan->fanSetup();
  solenoid->solenoidSetup();
  commmunication->livelinessSetup();
  commmunication->fan = fan;
  commmunication->leds = leds;
  solenoid->leds = leds;
  solenoid->communication = commmunication;
  solenoid->motor = motor;
  //while (!packetUpdate()) {delay(10);}
};

void loop() {
  commmunication->packetUpdate();
  fan->setPwmSpeed(map(commmunication->internalTemperture, 72, 120, 0, 100));
  // lockProcessor(isLocked);
  // ledProcessor();
  // livelinessProbe();
};