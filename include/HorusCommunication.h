#pragma once
// External Imports
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class HorusCommunication {      
  private:
    unsigned long lastUnlocked;
    char esp32_data[4];

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

    void motorProcessor();

    void ledProcessor();
    
  public:
    HorusCommunication();

    bool isLocked = true;
    int internalTemperture;
    bool power = true;

    int westColorManual[4];
    int eastColorManual[4];
    int northColorManual[4];
    int southColorManual[4];
    int topColorManual[4];

    int westColor[3];
    int eastColor[3];
    int northColor[3];
    int southColor[3];
    int topColor[3];

    int westMotor;
    int eastMotor;
    int northMotor;
    int southMotor;
    int topMotor;

    bool packetUpdate();

};
