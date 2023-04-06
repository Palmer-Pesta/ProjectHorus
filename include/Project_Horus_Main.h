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

void serialEvent();

void setup();

void loop();