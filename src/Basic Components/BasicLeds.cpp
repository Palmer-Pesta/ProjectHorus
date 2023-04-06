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

void ManualLedAction::setColor(int red, int green, int blue) {
  setRed(red);
  setGreen(green);
  setBlue(blue);
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

void AutomaticLed::setColor(int red, int green, int blue) {
  setRed(red);
  setGreen(green);
  setBlue(blue);
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

void BasicLeds::setLeds(int red, int green, int blue, bool isManual) {
  if (isManual) {
    manualLed->setColor(red, green, blue);
    manualLed->setTimestamp(millis());
  }
  else {
    automaticLed->setColor(red, green, blue);
  }
  updateLEDs();
}

void BasicLeds::clearLEDs() {
  manualLed->setColor(0, 0, 0);
  automaticLed->setColor(0, 0, 0);
  updateLEDs();
}

int BasicLeds::getRed() {
  if (millis() - manualLed->getTimestamp() < LED_MANUAL_TIMEOUT) {
    return manualLed->getRed();
  }
  return automaticLed->getRed();
}

int BasicLeds::getGreen() {
  if (millis() - manualLed->getTimestamp() < LED_MANUAL_TIMEOUT) {
    return manualLed->getGreen();
  }
  return automaticLed->getGreen();
}

int BasicLeds::getBlue() {
  if (millis() - manualLed->getTimestamp() < LED_MANUAL_TIMEOUT) {
    return manualLed->getBlue();
  }
  return automaticLed->getBlue();
}