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
    unsigned long power_time_liveliness;
    unsigned long lock_time_liveliness;
    unsigned long west_time_liveliness;
    unsigned long east_time_liveliness;
    unsigned long south_time_liveliness;
    unsigned long north_time_liveliness;
    unsigned long top_time_liveliness;
    unsigned long fan_time_liveliness;
    unsigned long current_time_liveliness;

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
    
  public:
    HorusFan* fan;
    HorusLeds* leds;
    HorusMotor* motor;
    HorusSolenoid* solenoid;
    
    bool packetUpdate();

    void livelinessSetup();

    void livelinessProbe();
};
