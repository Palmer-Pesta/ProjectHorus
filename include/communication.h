#pragma once
// Internal Imports
#include "fan.h"
#include "leds.h"
#include "motors.h"
#include "solenoid.h"
#include "config.h"

class HorusCommunication {      
  private:
    unsigned long lastUnlocked;
    char esp32_data[4];
    // Liveliness Probe
    unsigned long power_time;
    unsigned long lock_time;
    unsigned long west_time;
    unsigned long east_time;
    unsigned long south_time;
    unsigned long north_time;
    unsigned long top_time;
    unsigned long fan_time;
    unsigned long current_time;
  public:
    HorusFan* fan;
    HorusLeds* leds;
    HorusMotor* motor;
    HorusSolenoid* solenoid;
    
    int internalTemperture;
    bool isLocked = true;
    bool isHome = false;
    bool kitchen_motion = false;
    bool living_room_motion = false;
    bool bathroom_motion = false;
    bool bedroom_motion = false;
    bool closet_motion = false;
    bool toaster = false;
    bool air_fryer = false;
    bool rice_cooker = false;
    bool tv = false;
    bool shower = false;
    bool computer = false;
    bool in_bed = false;
    bool power = true;

    // Lights
    int brightness;
    int red;
    int green;
    int blue;
    bool west_light = false;
    bool east_light = false;
    bool north_light = false;
    bool south_light = false;
    bool top_light = false;
    
    bool packetUpdate();

    void livelinessSetup();

    void livelinessProbe();
};
