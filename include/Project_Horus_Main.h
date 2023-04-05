#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "leds.h"
#include "communication.h"
#include "fan.h"
#include "motors.h"
#include "solenoid.h"
#include "config.h"

HorusCommunication* communication;
HorusFan* fan;
HorusLeds* leds;
HorusMotor* motor;
HorusSolenoid* solenoid;

void serialEvent();

void setup();

void loop();