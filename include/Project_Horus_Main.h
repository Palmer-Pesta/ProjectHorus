#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "HorusCommunication.h"
#include "HorusMotors.h"
#include "HorusLeds.h"
#include "Basic Components\BasicSolenoid.h"
#include "Basic Components\BasicFan.h"
#include "config.h"

HorusCommunication* communication;
BasicFan* fan;
HorusLeds* leds;
HorusMotors* motors;
BasicSolenoid* solenoid;

bool power = true;

unsigned long current_time_liveliness = millis();
unsigned long power_time_liveliness = millis() + 250;
unsigned long lock_time_liveliness = millis() + 500;
unsigned long west_time_liveliness = millis() + 750;
unsigned long east_time_liveliness = millis() + 1000;
unsigned long north_time_liveliness = millis() + 1250;
unsigned long south_time_liveliness = millis() + 1500;
unsigned long top_time_liveliness = millis() + 1750;
unsigned long fan_time_liveliness = millis() + 2000;

