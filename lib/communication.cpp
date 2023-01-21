#include <Arduino.h>
// Internal Imports
#include "../config.h"
#include "fan.cpp"
#include "leds.cpp"

class HorusCommunication {      
  private:
    unsigned long lastUnlocked;
    char esp32_data[4];
    unsigned long current_time;
  public:
    HorusFan* fan = new HorusFan();
    HorusLeds* leds = new HorusLeds();
    // Liveliness Probe
    unsigned long power_time;
    unsigned long lock_time;
    unsigned long west_time;
    unsigned long east_time;
    unsigned long south_time;
    unsigned long north_time;
    unsigned long top_time;
    unsigned long fan_time;

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
    bool west_light = false;
    int west_brightness;
    int west_red;
    int west_green;
    int west_blue;
    bool east_light = false;
    bool north_light = false;
    bool south_light = false;
    bool top_light = false;

    void communicationSetup() {
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
                west_red = esp32_data[1];
                west_green = esp32_data[2];
                west_blue = esp32_data[3];
                leds->westColor(west_red, west_green, west_blue);
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
            uint8_t buf[] = {FAN, (uint8_t) fan->getPwmSpeed(), 0, 0};
            Serial.write(buf, 4);
            fan_time = millis() + probe_interval;
        }
    }
};
