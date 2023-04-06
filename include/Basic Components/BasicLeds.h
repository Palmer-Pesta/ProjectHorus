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

    int brightness = LED_DEFAULT_BRIGHTNESS;

    bool isOn = false;

    unsigned long timestamp = millis() - LED_MANUAL_TIMEOUT;

  public:
    ManualLedAction();

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
    AutomaticLed();

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

    void setLeds(int red, int green, int blue, bool isManual);

    void clearLEDs();
};
