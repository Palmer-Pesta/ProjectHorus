#pragma once
// External Imports
#include <FastLED.h>
// Internal Imports
#include "config.h"

class ManualLedAction {
  private:
    int red = 255;

    int blue = 255;

    int green = 255;

    int brightness = LED_DEFAULT_BRIGHTNESS;

    bool isOn = false;

    unsigned long timestamp = 0;

  public:
    void setRed(int redValue);

    int getRed();

    void setGreen(int greenValue);

    int getGreen();

    void setBlue(int blueValue);

    int getBlue();

    void setBrightness(int brightnessValue);

    int getBrightness();

    void setIsOn(bool state);

    bool getIsOn();

    void setTimestamp(unsigned long setTime);

    unsigned long getTimestamp();
};

class AutomaticLed {
  private:
    int red = 255;

    int blue = 255;

    int green = 255;

    int brightness = LED_DEFAULT_BRIGHTNESS;

    bool isOn = false;

  public:
    void setRed(int redValue);

    int getRed();

    void setGreen(int greenValue);

    int getGreen();

    void setBlue(int blueValue);

    int getBlue();

    void setBrightness(int brightnessValue);

    int getBrightness();

    void setIsOn(bool state);

    bool getIsOn();
};

class HorusLeds {      
  private:
    CRGB leds[NUM_LEDS]; // The array of LED colors

  public:        
    // Manual Actions LED Commands
    ManualLedAction manualWestLeds;
    ManualLedAction manualEastLeds;
    ManualLedAction manualNorthLeds;
    ManualLedAction manualSouthLeds;
    ManualLedAction manualTopLeds;

    // Automatic Actions LED Commands
    AutomaticLed autoWestLeds;
    AutomaticLed autoEastLeds;
    AutomaticLed autoNorthLeds;
    AutomaticLed autoSouthLeds;
    AutomaticLed autoTopLeds;

    void ledSetup();

    void updateLEDs();

    void rgb_to_hsv(double r, double g, double b, int brightness, int ledNumber);

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

    // Update LEDs
    void setWest();

    void setEast();

    void setNorth();

    void setSouth();

    void setTop();
};
