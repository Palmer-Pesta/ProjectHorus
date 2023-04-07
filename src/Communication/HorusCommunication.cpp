// Interal Imports
#include "HorusCommunication.h"
// Update the system data

HorusCommunication::HorusCommunication() {
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
}

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
                westColorManual[0] = esp32_data[1];
                westColorManual[1] = esp32_data[2];
                westColorManual[2] = esp32_data[3];
                break;
            case EAST_LIGHT_COLOR:
                eastColorManual[0] = esp32_data[1];
                eastColorManual[1] = esp32_data[2];
                eastColorManual[2] = esp32_data[3];
                break;
            case NORTH_LIGHT_COLOR:
                northColorManual[0] = esp32_data[1];
                northColorManual[1] = esp32_data[2];
                northColorManual[2] = esp32_data[3];
                break;
            case SOUTH_LIGHT_COLOR:
                southColorManual[0] = esp32_data[1];
                southColorManual[1] = esp32_data[2];
                southColorManual[2] = esp32_data[3];
                break;
            case TOP_LIGHT_COLOR:
                topColorManual[0] = esp32_data[1];
                topColorManual[1] = esp32_data[2];
                topColorManual[2] = esp32_data[3];
                break;
            case WEST_LIGHT:
                if (esp32_data[1]) {
                    westColorManual[3] = millis() - LED_MANUAL_TIMEOUT;
                }
                else {
                    westColorManual[0] = 0;
                    westColorManual[1] = 0;
                    westColorManual[2] = 0;
                    westColorManual[3] = millis();
                }
                break;
            case EAST_LIGHT:
                if (esp32_data[1]) {
                    eastColorManual[3] = millis() - LED_MANUAL_TIMEOUT;
                }
                else {
                    eastColorManual[0] = 0;
                    eastColorManual[1] = 0;
                    eastColorManual[2] = 0;
                    eastColorManual[3] = millis();
                }
                break;
            case NORTH_LIGHT:
                if (esp32_data[1]) {
                    northColorManual[3] = millis() - LED_MANUAL_TIMEOUT;
                }
                else {
                    northColorManual[0] = 0;
                    northColorManual[1] = 0;
                    northColorManual[2] = 0;
                    northColorManual[3] = millis();
                }
                break;
            case SOUTH_LIGHT:
                if (esp32_data[1]) {
                    southColorManual[3] = millis() - LED_MANUAL_TIMEOUT;
                }
                else {
                    southColorManual[0] = 0;
                    southColorManual[1] = 0;
                    southColorManual[2] = 0;
                    southColorManual[3] = millis();
                }
                break;
            case TOP_LIGHT:
                if (esp32_data[1]) {
                    topColorManual[3] = millis() - LED_MANUAL_TIMEOUT;
                }
                else {
                    topColorManual[0] = 0;
                    topColorManual[1] = 0;
                    topColorManual[2] = 0;
                    topColorManual[3] = millis();
                }
                break;
            default:
                break;
        }
        packetReceived = true;
    }
    if (packetReceived) {
        motorProcessor();
        ledProcessor();
    }
    return packetReceived;
}

/*
 * Based on the state of the home change the LEDs 
*/
void HorusCommunication::ledProcessor() {
  // Check the kitchen and set the west side lights
  if (kitchen_motion || rice_cooker || toaster || air_fryer) { 
    westColor[0] = 255;
    westColor[1] = 0;
    westColor[2] = 0;
  }
  else {
    westColor[0] = 255;
    westColor[1] = 0;
    westColor[2] = 0;
  }

  // Check the bedroom and set teh east side lights
  if (bedroom_motion || computer) {
    eastColor[0] = 67;
    eastColor[1] = 0;
    eastColor[2] = 112;
  }
  else {
    eastColor[0] = 0;
    eastColor[1] = 0;
    eastColor[2] = 0;
  }

  // Check the livingroom and set the north side lights
  if (tv) { // TODO: Add Livingroom Motion
    northColor[0] = 0;
    northColor[1] = 255;
    northColor[2] = 0;
  }
  else {
    northColor[0] = 0;
    northColor[1] = 0;
    northColor[2] = 0;
  }

  // Check the Bathroom and set the southern side lights
  if (bathroom_motion) {
    southColor[0] = 0;
    southColor[1] = 0;
    southColor[2] = 255;
  }
  else if (shower) {
    southColor[0] = 0;
    southColor[1] = 100;
    southColor[2] = 100;
  }
  else {
    southColor[0] = 0;
    southColor[1] = 0;
    southColor[2] = 0;
  }

  // Check if I am home and set the top lights
  if (isHome && !in_bed) {
    topColor[0] = 255;
    topColor[1] = 255;
    topColor[2] = 255;
  }
  else {
    topColor[0] = 0;
    topColor[1] = 0;
    topColor[2] = 0;
  }
}

/*
 * Based on the state of the home change the LEDs 
*/
void HorusCommunication::motorProcessor() {
  westMotor = 0;
  if (kitchen_motion || rice_cooker || toaster || air_fryer) { 
    if (kitchen_motion) {
        westMotor += 25;
    }
    if (rice_cooker) {
        westMotor += 25;
    }
    if (toaster) {
        westMotor += 25;
    }
    if (air_fryer) {
        westMotor += 25;
    }
  }

  // Check the bedroom and set teh east side lights
  if (bedroom_motion || computer) {
    eastMotor = 100;
  }
  else {
    eastMotor = 0;
  }

  // Check the livingroom and set the north side lights
  if (tv) { // TODO: Add Livingroom Motion
    northMotor = 100;
  }
  else {
    northMotor = 0;
  }

  // Check the Bathroom and set the southern side lights
  if (bathroom_motion) {
    southMotor = 100;
  }
  else if (shower) {
    southMotor = 50;
  }
  else {
    southMotor = 0;
  }

  // Check if I am home and set the top lights
  if (isHome && !in_bed) {
    topMotor = 100;
  }
  else {
    topMotor = 0;
  }
}
