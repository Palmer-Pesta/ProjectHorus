// Internal Imports
#include "Basic Components\BasicLeds.h"

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
ManualLedAction::ManualLedAction() {
    timestamp = millis() - LED_MANUAL_TIMEOUT;
}

void ManualLedAction::setRed(int redValue) {
  red = (int) (redValue);
}

int ManualLedAction::getRed() {
  return red;
}

void ManualLedAction::setGreen(int greenValue) {
  green = (int) (greenValue);
}

int ManualLedAction::getGreen() {
  return green;
}

void ManualLedAction::setBlue(int blueValue) {
  blue = (int) (blueValue);
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
AutomaticLed::AutomaticLed() {
}

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
// Main LED Class

BasicLeds::BasicLeds(int beginLedNumber, int endLedNumber, CRGB ledArrayAddress[]) {
  manualLed = new ManualLedAction();
  automaticLed = new AutomaticLed();
  leds = ledArrayAddress;
  beginLed = beginLedNumber;
  endLed = endLedNumber;
}

void BasicLeds::setLeds(int red, int green, int blue, bool isManual) {
  if (isManual) {
    manualLed->setRed(red);
    manualLed->setGreen(green);
    manualLed->setBlue(blue);
    manualLed->setTimestamp(millis());
  }
  else {
    automaticLed->setRed(red);
    automaticLed->setGreen(green);
    automaticLed->setBlue(blue);
  }
  updateLEDs();
}

void BasicLeds::updateLEDs() {
  if (millis() - manualLed->getTimestamp() < LED_MANUAL_TIMEOUT) {
    for (int i = beginLed; i<=endLed; i++) {
      leds[i] = CRGB(manualLed->getRed(), manualLed->getGreen(), manualLed->getBlue());
    }
  }
  else {
    for (int i = beginLed; i<=endLed; i++) {
      leds[i] = CRGB(automaticLed->getRed(), automaticLed->getGreen(), automaticLed->getBlue());
    }
  }
  FastLED.show();
}

void BasicLeds::clearLEDs() {
  for (int i = beginLed; i<=endLed; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}