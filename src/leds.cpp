// External Imports
#include <Arduino.h>
// Internal Imports
#include "leds.h"

/*
RED: CRGB(255,0,0);
BLUE: CRGB(0,0,255);
GREEN: CRGB(0,255,0); `
ORANGE: CRGB(255,75,0);
PURPLE: CRGB(128,0,128);
WHITE: CRGB(255,255,255);
CYAN: CRGB(0,100,100);
*/

void HorusLeds::ledSetup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // Setup LEDs
  clearLEDs();
  FastLED.setBrightness(50);
}

// Clear LEDS
bool HorusLeds::clearLEDs() {
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  return true;
}

void HorusLeds::turnOnWest() {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
}

void HorusLeds::turnOnEast() {
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
}

void HorusLeds::turnOnNorth() {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
}

void HorusLeds::turnOnSouth() {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
}

void HorusLeds::turnOnTop() {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(255,255,255);
  }
  FastLED.show();
}

void HorusLeds::turnOffWest() {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void HorusLeds::turnOffEast() {
  for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void HorusLeds::turnOffNorth() {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void HorusLeds::turnOffSouth() {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void HorusLeds::turnOffTop() {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

// Color
void HorusLeds::westColor(int red, int green, int blue) {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}

void HorusLeds::eastColor(int red, int green, int blue) {
  for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}

void HorusLeds::northColor(int red, int green, int blue) {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}

void HorusLeds::southColor(int red, int green, int blue) {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}

void HorusLeds::topColor(int red, int green, int blue) {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}
