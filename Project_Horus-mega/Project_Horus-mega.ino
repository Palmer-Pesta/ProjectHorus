// Internal Imports
#include "config.h"
// External Imports
#include <Stepper.h>
#include <FastLED.h>
#include <HardwareSerial.h>

// Liveliness Probe
unsigned long current_time;
unsigned long power_time;
unsigned long lock_time;
unsigned long west_time;
unsigned long east_time;
unsigned long south_time;
unsigned long north_time;
unsigned long top_time;
unsigned long fan_time;

char esp32_data[4];
int internalTemperture;
bool isLocked;
bool isHome;
bool kitchen_motion;
bool living_room_motion;
bool bathroom_motion;
bool bedroom_motion;
bool closet_motion;
bool toaster;
bool air_fryer;
bool rice_cooker;
bool tv;
bool shower;
bool computer;
bool in_bed;
bool power;

// Lights
bool west_light;
int west_brightness;
int west_red;
int west_green;
int west_blue;

bool east_light;

bool north_light;

bool south_light;

bool top_light;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  motorSetup();
  ledSetup();
  fanSetup();
  solenoidSetup();
  livelinessSetup();

  isLocked = true;
  isHome = false;
  kitchen_motion = false;
  living_room_motion = false;
  bathroom_motion = false;
  bedroom_motion = false;
  closet_motion = false;
  toaster = false;
  air_fryer = false;
  rice_cooker = false;
  tv = false;
  shower = false;
  computer = false;
  in_bed = false;
  power = true;
  west_light = false;
  east_light = false;
  north_light = false;
  south_light = false;
  top_light = false;

  //while (!packetUpdate()) {delay(10);}
}

void loop() {
  packetUpdate();
  setPwmSpeed(map(internalTemperture, 72, 120, 0, 100));
  // lockProcessor(isLocked);
  //ledProcessor();
  livelinessProbe();
}

// Update the system data
// @returns Wither an update has been preformed
bool packetUpdate() {
  bool packetReceived = false;
  while (Serial.available() > 0) { // Check for a packet update
    Serial.readBytes(esp32_data, 4);
    switch(esp32_data[0]) {
      case TEMPERATURE:
        internalTemperture = esp32_data[1];
        break;
      case LOCK:
        isLocked = esp32_data[1];
        break;
      case HOME:
        isHome = esp32_data[1];
        break;
      case KITCHEN_MOTION:
        kitchen_motion = esp32_data[1];
        break;
      case LIVINGROOM_MOTION:
        living_room_motion = esp32_data[1];
        break;
      case BATHROOM_MOTION:
        bathroom_motion = esp32_data[1];
        break;
      case BEDROOM_MOTION:
        bedroom_motion = esp32_data[1];
        break;
      case CLOSET_MOTION:
        closet_motion = esp32_data[1];
        break;
      case TOASTER:
        toaster = esp32_data[1];
        break;
      case AIR_FRYER:
        air_fryer = esp32_data[1];
        break;
      case RICE_COOKER:
        rice_cooker = esp32_data[1];
        break;
      case TV:
        tv = esp32_data[1];
        break;
      case SHOWER:
        shower = esp32_data[1];
        break;
      case COMPUTER:
        computer = esp32_data[1];
        break;
      case BED:
        in_bed = esp32_data[1];
        break;
      case POWER:
        power = esp32_data[1];
        break;
      case WEST_LIGHT:
        west_light = esp32_data[1];
        break;
      case 18:
        int west_red = esp32_data[1];
        int west_green = esp32_data[2];
        int west_blue = esp32_data[3];
        westColor(west_red, west_green, west_blue);
        break;
      case EAST_LIGHT:
        east_light = esp32_data[1];
        break;
      case NORTH_LIGHT:
        north_light = esp32_data[1];
        break;
      case SOUTH_LIGHT:
        south_light = esp32_data[1];
        break;
      case TOP_LIGHT:
        top_light = esp32_data[1];
        break;
      default:
        break;
    }
    packetReceived = true;

  }
  return packetReceived;
}

void livelinessSetup() {
  current_time = millis();
  power_time = millis() + 250;
  lock_time = millis() + 500;
  west_time = millis() + 750;
  east_time = millis() + 1000;
  north_time = millis() + 1250;
  south_time = millis() + 1500;
  top_time = millis() + 1750;
  fan_time = millis() + 2000;
}

void livelinessProbe() {
  current_time = millis();
  if (current_time >= power_time) {
    if (power) {
      uint8_t buf[] = {POWER, 1, 0, 0};
      Serial.write(buf, 4);
    }
    else {
      uint8_t buf[] = {POWER, 0, 0, 0};
      Serial.write(buf, 4);
    }
    power_time = millis() + probe_interval;
  }

  if (current_time >= lock_time) {
    if (digitalRead(SOLENOID_PIN)) {
      uint8_t buf[] = {LOCK, 1, 0, 0};
      Serial.write(buf, 4);
    }
    else {
      uint8_t buf[] = {LOCK, 0, 0, 0};
      Serial.write(buf, 4);
    }
    lock_time = millis() + probe_interval;
  }

  if (current_time >= west_time) {
    west_time = millis() + probe_interval;
  }

  if (current_time >= east_time) {
    east_time = millis() + probe_interval;
  }

  if (current_time >= north_time) {
    north_time = millis() + probe_interval;
  }

  if (current_time >= south_time) {
    south_time = millis() + probe_interval;
  }

  if (current_time >= top_time) {
    top_time = millis() + probe_interval;
  }

  if (current_time >= fan_time) {
    uint8_t buf[] = {FAN, getPwmSpeed(), 0, 0};
    Serial.write(buf, 4);
    fan_time = millis() + probe_interval;
  }
}
