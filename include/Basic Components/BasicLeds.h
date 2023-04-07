#pragma once
// External Imports
#include <FastLED.h>
#include <Arduino.h>
// Internal Imports
#include "Config.h"

class ManualLedAction {
  private:
    int red = 255;

    int blue = 255;

    int green = 255;

    unsigned long timestamp;

    void setBlue(int blueValue);

    void setRed(int redValue);

    void setGreen(int greenValue);

  public:
    ManualLedAction();

    int getRed();

    int getGreen();

    int getBlue();

    void setColor(int red, int green, int blue);

    void setTimestamp(unsigned long setTime);

    unsigned long getTimestamp();
};

class AutomaticLed {
  private:
    int red = 255;

    int blue = 255;

    int green = 255;

    void setRed(int redValue);

    void setGreen(int greenValue);

    void setBlue(int blueValue);

  public:
    AutomaticLed();

    int getRed();

    int getGreen();

    int getBlue();

    void setColor(int red, int green, int blue);
};

class BasicLeds {      
  private:
    ManualLedAction* manualLed;

    AutomaticLed* automaticLed;

    void updateLEDs();

    int beginLed;
    
    int endLed;
    
    CRGB* leds;

  public:    
    BasicLeds(int beginLedNumber, int endLedNumber, CRGB ledArrayAddress[]);

    void setLeds(int red, int green, int blue, unsigned long timestamp = 0);

    int getRed();

    int getGreen();

    int getBlue();

    void clearLEDs();
};
