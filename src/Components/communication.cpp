// Interal Imports
#include "Communication.h"
// Update the system data
// @returns Weither an update has been preformed
bool HorusCommunication::packetUpdate() {
    bool packetReceived = false;

    while (Serial.available() >= 5) { // Check for a packet update
        Serial.readBytesUntil(32, esp32_data, 5);
        if (DEBUG == 1) {
            Serial.print(esp32_data[0], HEX);
            Serial.print('-');
            Serial.print(esp32_data[1], HEX);
            Serial.print('-');
            Serial.print(esp32_data[2], HEX);
            Serial.print('-');
            Serial.print(esp32_data[3], HEX);
            Serial.print('-');
            Serial.println(esp32_data[4], HEX);
        }

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
            case WEST_LIGHT_COLOR:
                leds->manualWestLeds.setRed(esp32_data[1]);
                leds->manualWestLeds.setGreen(esp32_data[2]);
                leds->manualWestLeds.setBlue(esp32_data[3]);
                leds->manualWestLeds.setBrightness(leds->autoWestLeds.getBrightness());
                leds->manualWestLeds.setIsOn(true);
                leds->manualWestLeds.setTimestamp(millis());
                leds->setWest();
                break;
            case EAST_LIGHT_COLOR:
                leds->manualEastLeds.setRed(esp32_data[1]);
                leds->manualEastLeds.setGreen(esp32_data[2]);
                leds->manualEastLeds.setBlue(esp32_data[3]);
                leds->manualEastLeds.setBrightness(leds->autoEastLeds.getBrightness());
                leds->manualEastLeds.setIsOn(true);
                leds->manualEastLeds.setTimestamp(millis());
                leds->setEast();
                break;
            case NORTH_LIGHT_COLOR:
                leds->manualNorthLeds.setRed(esp32_data[1]);
                leds->manualNorthLeds.setGreen(esp32_data[2]);
                leds->manualNorthLeds.setBlue(esp32_data[3]);
                leds->manualNorthLeds.setBrightness(leds->autoNorthLeds.getBrightness());
                leds->manualNorthLeds.setIsOn(true);
                leds->manualNorthLeds.setTimestamp(millis());
                leds->setNorth();
                break;
            case SOUTH_LIGHT_COLOR:
                leds->manualSouthLeds.setRed(esp32_data[1]);
                leds->manualSouthLeds.setGreen(esp32_data[2]);
                leds->manualSouthLeds.setBlue(esp32_data[3]);
                leds->manualSouthLeds.setBrightness(leds->autoSouthLeds.getBrightness());
                leds->manualSouthLeds.setIsOn(true);
                leds->manualSouthLeds.setTimestamp(millis());
                leds->setSouth();
                break;
            case TOP_LIGHT_COLOR:
                leds->manualTopLeds.setRed(esp32_data[1]);
                leds->manualTopLeds.setGreen(esp32_data[2]);
                leds->manualTopLeds.setBlue(esp32_data[3]);
                leds->manualTopLeds.setBrightness(leds->autoTopLeds.getBrightness());
                leds->manualTopLeds.setIsOn(true);
                leds->manualTopLeds.setTimestamp(millis());
                leds->setTop();
                break;
            case WEST_LIGHT:
                leds->manualWestLeds.setIsOn(esp32_data[1]);
                leds->manualWestLeds.setTimestamp(millis());
                leds->setWest();
                // TODO
                //leds->manualWestLeds.setBrightness(esp32_data[1]);
                break;
            case EAST_LIGHT:
                leds->manualEastLeds.setIsOn(esp32_data[1]);
                leds->manualEastLeds.setTimestamp(millis());
                leds->setEast();
                // TODO
                //leds->manualWestLeds.setBrightness(esp32_data[1]);
                break;
            case NORTH_LIGHT:
                leds->manualNorthLeds.setIsOn(esp32_data[1]);
                leds->manualNorthLeds.setTimestamp(millis());
                leds->setNorth();
                // TODO
                //leds->manualWestLeds.setBrightness(esp32_data[1]);
                break;
            case SOUTH_LIGHT:
                leds->manualSouthLeds.setIsOn(esp32_data[1]);
                leds->manualSouthLeds.setTimestamp(millis());
                leds->setSouth();
                // TODO
                //leds->manualWestLeds.setBrightness(esp32_data[1]);
                break;
            case TOP_LIGHT:
                leds->manualTopLeds.setIsOn(esp32_data[1]);
                leds->manualTopLeds.setTimestamp(millis());
                leds->setTop();
                // TODO
                //leds->manualWestLeds.setBrightness(esp32_data[1]);
                break;
            default:
                break;
        }
        packetReceived = true;
    }
    return packetReceived;
}

void HorusCommunication::livelinessSetup() {
    current_time_liveliness = millis();
    power_time_liveliness = millis() + 250;
    lock_time_liveliness = millis() + 500;
    west_time_liveliness = millis() + 750;
    east_time_liveliness = millis() + 1000;
    north_time_liveliness = millis() + 1250;
    south_time_liveliness = millis() + 1500;
    top_time_liveliness = millis() + 1750;
    fan_time_liveliness = millis() + 2000;
}

void HorusCommunication::livelinessProbe() {
    current_time_liveliness = millis();
    if (current_time_liveliness >= power_time_liveliness) {
        if (power) {
            uint8_t buf[] = {POWER, 1, 0, 0, 32};
            Serial.write(buf, 5);
        }
        else {
            uint8_t buf[] = {POWER, 0, 0, 0, 32};
            Serial.write(buf, 5);
        }
        power_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= lock_time_liveliness) {
        if (solenoid->getState() == true) {
            uint8_t buf[] = {LOCK, 1, 0, 0, 32};
            Serial.write(buf, 5);
        }
        else {
            uint8_t buf[] = {LOCK, 0, 0, 0, 32};
            Serial.write(buf, 5);
        }
        lock_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= west_time_liveliness) {
        uint8_t buf[] = {WEST_LIGHT_COLOR, 0, 0, 0, 32};
            
        if (leds->manualWestLeds.getIsOn() && leds->manualWestLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
            buf[1] = leds->manualWestLeds.getRed();
            buf[2] = leds->manualWestLeds.getGreen();
            buf[3] = leds->manualWestLeds.getBlue();
        }
        else if (leds->autoWestLeds.getIsOn()) {
            buf[1] = leds->autoWestLeds.getRed();
            buf[2] = leds->autoWestLeds.getGreen();
            buf[3] = leds->autoWestLeds.getBlue();
        }
        else {
            buf[0] = WEST_LIGHT;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
        }
        Serial.write(buf, 5);
        west_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= east_time_liveliness) {
        uint8_t buf[] = {EAST_LIGHT_COLOR, 0, 0, 0, 32};
            
        if (leds->manualEastLeds.getIsOn() && leds->manualEastLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
            buf[1] = leds->manualEastLeds.getRed();
            buf[2] = leds->manualEastLeds.getGreen();
            buf[3] = leds->manualEastLeds.getBlue();
        }
        else if (leds->autoEastLeds.getIsOn()) {
            buf[1] = leds->autoEastLeds.getRed();
            buf[2] = leds->autoEastLeds.getGreen();
            buf[3] = leds->autoEastLeds.getBlue();
        }
        else {
            buf[0] = EAST_LIGHT;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
        }
        Serial.write(buf, 5);
        east_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= north_time_liveliness) {
        uint8_t buf[] = {NORTH_LIGHT_COLOR, 0, 0, 0, 32};
            
        if (leds->manualNorthLeds.getIsOn() && leds->manualNorthLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
            buf[1] = leds->manualNorthLeds.getRed();
            buf[2] = leds->manualNorthLeds.getGreen();
            buf[3] = leds->manualNorthLeds.getBlue();
        }
        else if (leds->autoNorthLeds.getIsOn()) {
            buf[1] = leds->autoNorthLeds.getRed();
            buf[2] = leds->autoNorthLeds.getGreen();
            buf[3] = leds->autoNorthLeds.getBlue();
        }
        else {
            buf[0] = NORTH_LIGHT;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
        }
        Serial.write(buf, 5);
        north_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= south_time_liveliness) {
        uint8_t buf[] = {SOUTH_LIGHT_COLOR, 0, 0, 0, 32};
            
        if (leds->manualSouthLeds.getIsOn() && leds->manualSouthLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
            buf[1] = leds->manualSouthLeds.getRed();
            buf[2] = leds->manualSouthLeds.getGreen();
            buf[3] = leds->manualSouthLeds.getBlue();
        }
        else if (leds->autoSouthLeds.getIsOn()) {
            buf[1] = leds->autoSouthLeds.getRed();
            buf[2] = leds->autoSouthLeds.getGreen();
            buf[3] = leds->autoSouthLeds.getBlue();
        }
        else {
            buf[0] = SOUTH_LIGHT;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
        }
        Serial.write(buf, 5);
        south_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= top_time_liveliness) {
        uint8_t buf[] = {TOP_LIGHT_COLOR, 0, 0, 0, 32};
            
        if (leds->manualTopLeds.getIsOn() && leds->manualTopLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
            buf[1] = leds->manualTopLeds.getRed();
            buf[2] = leds->manualTopLeds.getGreen();
            buf[3] = leds->manualTopLeds.getBlue();
        }
        else if (leds->autoTopLeds.getIsOn()) {
            buf[1] = leds->autoTopLeds.getRed();
            buf[2] = leds->autoTopLeds.getGreen();
            buf[3] = leds->autoTopLeds.getBlue();
        }
        else {
            buf[0] = TOP_LIGHT;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
        }
        Serial.write(buf, 5);
        top_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= fan_time_liveliness) {
        uint8_t buf[] = {FAN, (uint8_t) fan->getPwmSpeed(), 0, 0, 32};
        Serial.write(buf, 5);
        fan_time_liveliness = millis() + probe_interval;
    }
    Serial.flush();
}
