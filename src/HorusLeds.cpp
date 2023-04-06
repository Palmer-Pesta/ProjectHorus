
////////////////////////////////////////////////////////////////////////////////////////////
// LEDs Class
void HorusLeds::ledSetup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // Setup LEDs
  FastLED.setBrightness(LED_DEFAULT_BRIGHTNESS);
  clearLEDs();
}

// Clear LEDS
void HorusLeds::updateLEDs() {
  FastLED.show();
}

bool HorusLeds::clearLEDs() {
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoWestLeds.setIsOn(false);
  autoEastLeds.setIsOn(false);
  autoNorthLeds.setIsOn(false);
  autoSouthLeds.setIsOn(false);
  autoTopLeds.setIsOn(false);
  return true;
}

void HorusLeds::turnOffWest() {
  for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoWestLeds.setIsOn(false);
}

void HorusLeds::turnOffEast() {
  for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoEastLeds.setIsOn(false);
}

void HorusLeds::turnOffNorth() {
  for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoNorthLeds.setIsOn(false);
}

void HorusLeds::turnOffSouth() {
  for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoSouthLeds.setIsOn(false);
}

void HorusLeds::turnOffTop() {
  for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
    leds[i] = CRGB(0,0,0);
  }
  autoTopLeds.setIsOn(false);
}

// Update LED Color and Brightness
void HorusLeds::setWest() {
  if (manualWestLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
    if (manualWestLeds.getIsOn()) {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        // rgb_to_hsv(manualWestLeds.getRed(), manualWestLeds.getGreen(), manualWestLeds.getBlue(), manualWestLeds.getBrightness(), i);
        leds[i] = CRGB(manualWestLeds.getRed(), manualWestLeds.getGreen(), manualWestLeds.getBlue());
      }
    }
    else {
      turnOffWest();
    }
  }
  else {
    if (autoWestLeds.getIsOn()) {
      for (int i = WEST_LED_START; i<=WEST_LED_STOP; i++) {
        // rgb_to_hsv(autoWestLeds.getRed(), autoWestLeds.getGreen(), autoWestLeds.getBlue(), autoWestLeds.getBrightness(), i);
        leds[i] = CRGB(autoWestLeds.getRed(), autoWestLeds.getGreen(), autoWestLeds.getBlue());
      }
    }
    else {
      turnOffWest();
    }
  }
  updateLEDs();
}

void HorusLeds::setEast() {
  if (manualEastLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
    if (manualEastLeds.getIsOn()) {
      for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
        // rgb_to_hsv(manualEastLeds.getRed(), manualEastLeds.getGreen(), manualEastLeds.getBlue(), manualEastLeds.getBrightness(), i);
        leds[i] = CRGB(manualEastLeds.getRed(), manualEastLeds.getGreen(), manualEastLeds.getBlue());
      }
    }
    else {
      turnOffEast();
    }
  }
  else {
    if (autoEastLeds.getIsOn()) {
      for (int i = EAST_LED_START; i<=EAST_LED_STOP; i++) {
        // rgb_to_hsv(autoEastLeds.getRed(), autoEastLeds.getGreen(), autoEastLeds.getBlue(), autoEastLeds.getBrightness(), i);
        leds[i] = CRGB(autoEastLeds.getRed(), autoEastLeds.getGreen(), autoEastLeds.getBlue());
      }
    }
    else {
      turnOffEast();
    }
  }
  updateLEDs();
}

void HorusLeds::setNorth() {
  if (manualNorthLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
    if (manualNorthLeds.getIsOn()) {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        //rgb_to_hsv(autoEastLeds.getRed(), autoEastLeds.getGreen(), autoEastLeds.getBlue(), manualNorthLeds.getBrightness(), i);
        leds[i] = CRGB(manualNorthLeds.getRed(), manualNorthLeds.getGreen(), manualNorthLeds.getBlue());
      }
    }
    else {
      turnOffNorth();
    }
  }
  else {
    if (autoNorthLeds.getIsOn()) {
      for (int i = NORTH_LED_START; i<=NORTH_LED_STOP; i++) {
        // rgb_to_hsv(autoNorthLeds.getRed(), autoNorthLeds.getGreen(), autoNorthLeds.getBlue(), autoNorthLeds.getBrightness(), i);
        leds[i] = CRGB(autoNorthLeds.getRed(), autoNorthLeds.getGreen(), autoNorthLeds.getBlue());
      }
    }
    else {
      turnOffNorth();
    }
  }
  updateLEDs();
}

void HorusLeds::setSouth() {
  if (manualSouthLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
    if (manualSouthLeds.getIsOn()) {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        // rgb_to_hsv(manualSouthLeds.getRed(), manualSouthLeds.getGreen(), manualSouthLeds.getBlue(), manualSouthLeds.getBrightness(), i);
        leds[i] = CRGB(manualSouthLeds.getRed(), manualSouthLeds.getGreen(), manualSouthLeds.getBlue());
      }
    }
    else {
      turnOffSouth();
    }
  }
  else {
    if (autoSouthLeds.getIsOn()) {
      for (int i = SOUTH_LED_START; i<=SOUTH_LED_STOP; i++) {
        // rgb_to_hsv(autoSouthLeds.getRed(), autoSouthLeds.getGreen(), autoSouthLeds.getBlue(), autoSouthLeds.getBrightness(), i);
        leds[i] = CRGB(autoSouthLeds.getRed(), autoSouthLeds.getGreen(), autoSouthLeds.getBlue());
      }
    }
    else {
      turnOffSouth();
    }
  }
  updateLEDs();
}

void HorusLeds::setTop() {
  if (manualTopLeds.getTimestamp() + LED_MANUAL_TIMEOUT >= millis()) {
    if (manualTopLeds.getIsOn()) {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        // rgb_to_hsv(manualTopLeds.getRed(), manualTopLeds.getGreen(), manualTopLeds.getBlue(), manualTopLeds.getBrightness(), i);
        leds[i] = CRGB(manualTopLeds.getRed(), manualTopLeds.getGreen(), manualTopLeds.getBlue());
      }
    }
    else {
      turnOffTop();
    }
  }
  else {
    if (autoTopLeds.getIsOn()) {
      for (int i = TOP_LED_START; i<=TOP_LED_STOP; i++) {
        //rgb_to_hsv(autoTopLeds.getRed(), autoTopLeds.getGreen(), autoTopLeds.getBlue(), autoTopLeds.getBrightness(), i);
        leds[i] = CRGB(autoTopLeds.getRed(), autoTopLeds.getGreen(), autoTopLeds.getBlue());
      }
    }
    else {
      turnOffTop();
    }
  }
  updateLEDs();
}

/*
 * Based on the state of the home change the LEDs 
*/
void HorusLeds::ledProcessor(HorusCommunication* horusCommunication) {
  // Check the kitchen and set the west side lights
  if (horusCommunication->kitchen_motion || horusCommunication->rice_cooker || horusCommunication->toaster || horusCommunication->air_fryer) { 
    autoWestLeds.setRed(255);
    autoWestLeds.setGreen(0);
    autoWestLeds.setBlue(0);
    autoWestLeds.setIsOn(true);
    setWest();
  }
  else {
    turnOffWest();
  }

  // Check the bedroom and set teh east side lights
  if (horusCommunication->bedroom_motion || horusCommunication->computer) {
    autoEastLeds.setRed(67);
    autoEastLeds.setGreen(0);
    autoEastLeds.setBlue(112);
    autoEastLeds.setIsOn(true);
    setEast();
  }
  else {
    turnOffEast();
  }

  // Check the livingroom and set the north side lights
  if (horusCommunication->tv) { // TODO: Add Livingroom Motion
    autoNorthLeds.setRed(0);
    autoNorthLeds.setGreen(255);
    autoNorthLeds.setBlue(0);
    autoNorthLeds.setIsOn(true);
    setNorth();
  }
  else {
    turnOffNorth();
  }

  // Check the Bathroom and set the southern side lights
  if (horusCommunication->bathroom_motion) {
    autoSouthLeds.setRed(0);
    autoSouthLeds.setGreen(0);
    autoSouthLeds.setBlue(255);
    autoSouthLeds.setIsOn(true);
    setSouth();
  }
  else if (horusCommunication->shower) {
    autoSouthLeds.setRed(0);
    autoSouthLeds.setGreen(100);
    autoSouthLeds.setBlue(100);
    autoSouthLeds.setIsOn(true);
    setSouth();
  }
  else {
    turnOffSouth();
  }

  // Check if I am home and set the top lights
  if (horusCommunication->isHome && !horusCommunication->in_bed) {
    autoTopLeds.setRed(255);
    autoTopLeds.setGreen(255);
    autoTopLeds.setBlue(255);
    autoTopLeds.setIsOn(true);
    setTop();
  }
  else {
    turnOffTop();
  }
}
