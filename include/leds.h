#pragma once
// External Imports
#include <FastLED.h>
#include <Arduino.h>
// Internal Imports
#include "Config.h"
#include "Communication.h"

class ManualLedAction {
  private:
    int red = 255;

    int blue = 255;

    int green = 255;

    int brightness = LED_DEFAULT_BRIGHTNESS;

    bool isOn = false;

    unsigned long timestamp = millis() - LED_MANUAL_TIMEOUT;

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

    void ledSetup();

    void updateLEDs();

    bool clearLEDs();

    void rgb_to_hsv(double r, double g, double b, int brightness, int ledNumber);

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

    // Processor
    void ledProcessor(HorusCommunication* horusCommunication);
};
