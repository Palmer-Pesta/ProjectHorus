// External Import

// Internal Import
#include "HorusLeds.h"

////////////////////////////////////////////////////////////////////////////////////////////
// LEDs Class
HorusLeds::HorusLeds() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(ledRawArray, NUM_LEDS); // Setup LEDs
  setBrightness(LED_DEFAULT_BRIGHTNESS);
  westLeds = new BasicLeds(WEST_LED_START, WEST_LED_STOP, ledRawArray);
  eastLeds = new BasicLeds(EAST_LED_START, EAST_LED_STOP, ledRawArray);
  northLeds = new BasicLeds(NORTH_LED_START, NORTH_LED_STOP, ledRawArray);
  southLeds = new BasicLeds(SOUTH_LED_START, SOUTH_LED_STOP, ledRawArray);
  topLeds = new BasicLeds(TOP_LED_START, TOP_LED_STOP, ledRawArray);
}

BasicLeds* HorusLeds::getSection(String section) {
  if (section == "west") {
    return westLeds;
  }
  else if (section == "east") {
    return eastLeds;
  }
  else if (section == "north") {
    return northLeds;
  }
  else if (section == "south") {
    return southLeds;
  }
  else if (section == "top") {
    return topLeds;
  }
  return nullptr;
}

void HorusLeds::setColors(String section, int red, int green, int blue, unsigned long timestamp = 0) {
  BasicLeds* currentSection = getSection(section);
  currentSection->setLeds(red, green, blue, timestamp);
}

void HorusLeds::turnOffLights(String section, unsigned long timestamp = 0) {
  BasicLeds* currentSection = getSection(section);
  currentSection->setLeds(0, 0, 0, timestamp);
}

int HorusLeds::getRed(String section) {
  BasicLeds* currentSection = getSection(section);
  return currentSection->getRed();
}

int HorusLeds::getGreen(String section) {
  BasicLeds* currentSection = getSection(section);
  return currentSection->getGreen();
}

int HorusLeds::getBlue(String section) {
  BasicLeds* currentSection = getSection(section);
  return currentSection->getBlue();
}

void HorusLeds::setBrightness(int ledBrightness) {
  FastLED.setBrightness(ledBrightness);
}

int HorusLeds::getBrightness() {
  return FastLED.getBrightness();
}

void HorusLeds::reset() {
  westLeds->clearLEDs();
  eastLeds->clearLEDs();
  northLeds->clearLEDs();
  southLeds->clearLEDs();
  topLeds->clearLEDs();
}
