#pragma once
// External Imports
#include <FastLED.h>
#include <Arduino.h>
// Internal Imports
#include "Config.h"
#include "Basic Components\BasicLeds.h"

class HorusLeds {
  private:
    CRGB* ledRawArray;

    int brightness;

    BasicLeds* westLeds;

    BasicLeds* eastLeds;

    BasicLeds* northLeds;

    BasicLeds* southLeds;

    BasicLeds* topLeds;

    BasicLeds* getSection(String section);

  public:
    HorusLeds();

    void setColors(String section, int red, int green, int blue, unsigned long timestamp = 0);

    void turnOffLights(String section, unsigned long timestamp = 0);

    int getRed(String section);

    int getGreen(String section);

    int getBlue(String section);

    void setBrightness(int brightness);

    int getBrightness();

    void reset();
};
