// External Imports
#include <Arduino.h>
// Internal Imports
#include "leds.h"

/*
RED: CRGB(255,0,0);
BLUE: CRGB(0,0,255);
GREEN: CRGB(0,255,0); `
ORANGE: CRGB(255,75,0);
PURPLE: CRGB(128,0,128);
WHITE: CRGB(255,255,255);
CYAN: CRGB(0,100,100);
*/

////////////////////////////////////////////////////////////////////////////////////////////
// Manual Action Class
void ManualLedAction::setRed(int redValue) {
  red = redValue;
}

int ManualLedAction::getRed() {
  return red;
}

void ManualLedAction::setGreen(int greenValue) {
  green = greenValue;
}

int ManualLedAction::getGreen() {
  return green;
}

void ManualLedAction::setBlue(int blueValue) {
  blue = blueValue;
}

int ManualLedAction::getBlue() {
  return blue;
}

void ManualLedAction::setBrightness(int brightnessValue) {
  brightness = brightnessValue;
}

int ManualLedAction::getBrightness() {
  return brightness;
}

void ManualLedAction::setIsOn(bool state) {
  isOn = state;
}

bool ManualLedAction::getIsOn() {
  return isOn;
}

void ManualLedAction::setTimestamp(unsigned long setTime) {
  timestamp = setTime;
}

unsigned long ManualLedAction::getTimestamp() {
  return timestamp;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Automatic Action Class
void AutomaticLed::setRed(int redValue) {
  red = redValue;
}

int AutomaticLed::getRed() {
  return red;
}

void AutomaticLed::setGreen(int greenValue) {
  green = greenValue;
}

int AutomaticLed::getGreen() {
  return green;
}

void AutomaticLed::setBlue(int blueValue) {
  blue = blueValue;
}

int AutomaticLed::getBlue() {
  return blue;
}

void AutomaticLed::setBrightness(int brightnessValue) {
  brightness = brightnessValue;
}

int AutomaticLed::getBrightness() {
  return brightness;
}

void AutomaticLed::setIsOn(bool state) {
  isOn = state;
}

bool AutomaticLed::getIsOn() {
  return isOn;
}

////////////////////////////////////////////////////////////////////////////////////////////
// LEDs Class
void HorusLeds::ledSetup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // Setup LEDs
  clearLEDs();
}

// Clear LEDS
void HorusLeds::updateLEDs() {
  FastLED.show();
}

bool HorusLeds::clearLEDs() {
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  return true;
}

void HorusLeds::turnOnWest() {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
}

void HorusLeds::turnOnEast() {
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(255,255,255);
  }
}

void HorusLeds::turnOnNorth() {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
}

void HorusLeds::turnOnSouth() {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
}

void HorusLeds::turnOnTop() {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
}

void HorusLeds::turnOffWest() {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

void HorusLeds::turnOffEast() {
  for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

void HorusLeds::turnOffNorth() {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

void HorusLeds::turnOffSouth() {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

void HorusLeds::turnOffTop() {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

// Update LED Color and Brightness
void HorusLeds::setWest() {
  if (manualWestLeds.getTimestamp() >= millis() + LED_MANUAL_TIMEOUT) {
    for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
      if (manualWestLeds.getIsOn()) {
        rgb_to_hsv(manualWestLeds.getRed(), manualWestLeds.getGreen(), manualWestLeds.getBlue(), manualWestLeds.getBrightness(), i);
      }
      else {
        turnOffWest();
      }
    }
  }
  else {
    if (autoWestLeds.getIsOn()) {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        rgb_to_hsv(autoWestLeds.getRed(), autoWestLeds.getGreen(), autoWestLeds.getBlue(), autoWestLeds.getBrightness(), i);
      }
    }
    else {
      turnOffWest();
    }
  }
}

void HorusLeds::setEast() {
  if (manualEastLeds.getTimestamp() >= millis() + LED_MANUAL_TIMEOUT) {
    if (manualEastLeds.getIsOn()) {
      for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
        rgb_to_hsv(manualEastLeds.getRed(), manualEastLeds.getGreen(), manualEastLeds.getBlue(), manualEastLeds.getBrightness(), i);
      }
    }
    else {
      turnOffEast();
    }
  }
  else {
    if (autoEastLeds.getIsOn()) {
      for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
        rgb_to_hsv(autoEastLeds.getRed(), autoEastLeds.getGreen(), autoEastLeds.getBlue(), autoEastLeds.getBrightness(), i);
      }
    }
    else {
      turnOffEast();
    }
  }
}

void HorusLeds::setNorth() {
  if (manualNorthLeds.getTimestamp() >= millis() + LED_MANUAL_TIMEOUT) {
    if (manualEastLeds.getIsOn()) {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        rgb_to_hsv(manualNorthLeds.getRed(), manualNorthLeds.getGreen(), manualNorthLeds.getBlue(), manualNorthLeds.getBrightness(), i);
      }
    }
    else {
      turnOffNorth();
    }
  }
  else {
    if (autoNorthLeds.getIsOn()) {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        rgb_to_hsv(autoNorthLeds.getRed(), autoNorthLeds.getGreen(), autoNorthLeds.getBlue(), autoNorthLeds.getBrightness(), i);
      }
    }
    else {
      turnOffNorth();
    }
  }
}

void HorusLeds::setSouth() {
  if (manualSouthLeds.getTimestamp() >= millis() + LED_MANUAL_TIMEOUT) {
    if (manualSouthLeds.getIsOn()) {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        rgb_to_hsv(manualSouthLeds.getRed(), manualSouthLeds.getGreen(), manualSouthLeds.getBlue(), manualSouthLeds.getBrightness(), i);
      }
    }
    else {
      turnOffSouth();
    }
  }
  else {
    if (autoSouthLeds.getIsOn()) {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        rgb_to_hsv(autoSouthLeds.getRed(), autoSouthLeds.getGreen(), autoSouthLeds.getBlue(), autoSouthLeds.getBrightness(), i);
      }
    }
    else {
      turnOffSouth();
    }
  }
}

void HorusLeds::setTop() {
  if (manualTopLeds.getTimestamp() >= millis() + LED_MANUAL_TIMEOUT) {
    if (manualTopLeds.getIsOn()) {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        rgb_to_hsv(manualTopLeds.getRed(), manualTopLeds.getGreen(), manualTopLeds.getBlue(), manualTopLeds.getBrightness(), i);
      }
    }
    else {
      turnOffTop();
    }
  }
  else {
    if (autoTopLeds.getIsOn()) {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        rgb_to_hsv(autoTopLeds.getRed(), autoTopLeds.getGreen(), autoTopLeds.getBlue(), autoTopLeds.getBrightness(), i);
      }
    }
    else {
      turnOffTop();
    }
  }
}

void HorusLeds::rgb_to_hsv(double r, double g, double b, int brightness, int ledNumber) {
    r = r / 255.0;
    g = g / 255.0;
    b = b / 255.0;
 
    double cmax = max(r, max(g, b));
    double cmin = min(r, min(g, b));
    double diff = cmax - cmin;
    double h = -1, s = -1;
 
    if (cmax == cmin) {
      h = 0;
    }
    else if (cmax == r) {
        h = fmod(60 * ((g - b) / diff) + 360, 360);
    }
    else if (cmax == g) {
        h = fmod(60 * ((b - r) / diff) + 120, 360);
    }
    else if (cmax == b) {
      h = fmod(60 * ((r - g) / diff) + 240, 360);
    }

    if (cmax == 0) {
      s = 0;
    }
    else {
      s = (diff / cmax) * 100;
    }

    double v = cmax * 100;

    leds[ledNumber] = CHSV(h, s, v * brightness);
}
