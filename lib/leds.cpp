// External Imports
#include <Arduino.h>
#include <FastLED.h>
// Internal Imports
#include "../config.h"


/*
RED: CRGB(255,0,0);
BLUE: CRGB(0,0,255);
GREEN: CRGB(0,255,0);
ORANGE: CRGB(255,75,0);
PURPLE: CRGB(128,0,128);
WHITE: CRGB(255,255,255);
CYAN: CRGB(0,100,100);
*/

class HorusLeds {      
  private:
    CRGB leds[NUM_LEDS]; // The array of LED colors
  public:            
    bool isHome = false;
    bool kitchen_motion = false;
    bool living_room_motion = false;
    bool bathroom_motion = false;
    bool bedroom_motion = false;
    bool closet_motion = false;
    bool west_light = false;
    bool east_light = false;
    bool north_light = false;
    bool south_light = false;
    bool top_light = false;
      
    void ledSetup() {
      FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // Setup LEDs
      clearLEDs();
      FastLED.setBrightness(50);
    }

    void ledProcessor() {
      if (isHome || west_light) {
        turnOnWest();
      }
      else {
        turnOffWest();
      }
      if (kitchen_motion || east_light) {
        turnOnEast();
      }
      else {
        turnOffEast();
      }
      if (living_room_motion || north_light) {
        turnOnNorth();
      }
      else {
        turnOffNorth();
      }
      if (bathroom_motion || south_light) {
        turnOnSouth();
      }
      else {
        turnOffSouth();
      }
      if (bedroom_motion || closet_motion || top_light) {
        turnOnTop();
      }
      else {
        turnOffTop();
      }
    } 

    // Clear LEDS
    bool clearLEDs() {
      for (int i = 0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
      return true;
    }

    void turnOnWest() {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        leds[i] = CRGB(255,255,255);
      }
      FastLED.show();
    }

    void westColor(int red, int green, int blue) {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        leds[i] = CRGB(red, green, blue);
      }
      FastLED.show();
    }

    void turnOnEast() {
      for (int i = 0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(255,255,255);
      }
      FastLED.show();
    }

    void turnOnNorth() {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        leds[i] = CRGB(255,255,255);
      }
      FastLED.show();
    }

    void turnOnSouth() {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        leds[i] = CRGB(255,255,255);
      }
      FastLED.show();
    }

    void turnOnTop() {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        leds[i] = CRGB(255,255,255);
      }
      FastLED.show();
    }

    void turnOffWest() {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
    }

    void turnOffEast() {
      for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
    }

    void turnOffNorth() {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
    }

    void turnOffSouth() {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
    }

    void turnOffTop() {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        leds[i] = CRGB(0,0,0);
      }
      FastLED.show();
    }
};



