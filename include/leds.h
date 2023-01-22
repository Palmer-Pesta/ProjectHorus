#pragma once
// External Imports
#include <FastLED.h>
// Internal Imports
#include "config.h"

class HorusLeds {      
  private:
    CRGB leds[NUM_LEDS]; // The array of LED colors
  public:        
      
    void ledSetup();

    // Clear LEDS
    bool clearLEDs();

    void turnOnWest();

    void turnOnEast();

    void turnOnNorth();

    void turnOnSouth();

    void turnOnTop();

    void turnOffWest();

    void turnOffEast();

    void turnOffNorth();

    void turnOffSouth();

    void turnOffTop();

    // Color
    void westColor(int red, int green, int blue);

    void eastColor(int red, int green, int blue);

    void northColor(int red, int green, int blue);

    void southColor(int red, int green, int blue);

    void topColor(int red, int green, int blue);
};
