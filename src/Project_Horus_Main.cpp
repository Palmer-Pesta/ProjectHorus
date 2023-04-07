// Internal Imports
#include "Project_Horus_Main.h"

void serialEvent() {
  // Packet Update
  communication->packetUpdate();
}

void livelinessProbe() {
    current_time_liveliness = millis();
    if (current_time_liveliness >= power_time_liveliness) {
        if (communication->power) {
            uint8_t buf[] = {POWER, 1, 0, 0, 32};
            Serial.write(buf, 5);
        }
        else {
            uint8_t buf[] = {POWER, 0, 0, 0, 32};
            Serial.write(buf, 5);
        }
        power_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= lock_time_liveliness) {
        if (solenoid->getState() == true) {
            uint8_t buf[] = {LOCK, 1, 0, 0, 32};
            Serial.write(buf, 5);
        }
        else {
            uint8_t buf[] = {LOCK, 0, 0, 0, 32};
            Serial.write(buf, 5);
        }
        lock_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= west_time_liveliness) {
        uint8_t buf[] = {WEST_LIGHT_COLOR, 0, 0, 0, 32};
        buf[1] = leds->getRed("west");
        buf[2] = leds->getGreen("west");
        buf[3] = leds->getBlue("west");
        Serial.write(buf, 5);
        west_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= east_time_liveliness) {
        uint8_t buf[] = {EAST_LIGHT_COLOR, 0, 0, 0, 32};
        buf[1] = leds->getRed("east");
        buf[2] = leds->getGreen("east");
        buf[3] = leds->getBlue("east");
        Serial.write(buf, 5);
        east_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= north_time_liveliness) {
        uint8_t buf[] = {NORTH_LIGHT_COLOR, 0, 0, 0, 32};
        buf[1] = leds->getRed("north");
        buf[2] = leds->getGreen("north");
        buf[3] = leds->getBlue("north");
        Serial.write(buf, 5);
        north_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= south_time_liveliness) {
        uint8_t buf[] = {SOUTH_LIGHT_COLOR, 0, 0, 0, 32};
        buf[1] = leds->getRed("south");
        buf[2] = leds->getGreen("south");
        buf[3] = leds->getBlue("south");
        Serial.write(buf, 5);
        south_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= top_time_liveliness) {
        uint8_t buf[] = {TOP_LIGHT_COLOR, 0, 0, 0, 32};
        buf[1] = leds->getRed("top");
        buf[2] = leds->getGreen("top");
        buf[3] = leds->getBlue("top");
        Serial.write(buf, 5);
        top_time_liveliness = millis() + probe_interval;
    }

    if (current_time_liveliness >= fan_time_liveliness) {
        uint8_t buf[] = {FAN, (uint8_t) fan->getPwmSpeed(), 0, 0, 32};
        Serial.write(buf, 5);
        fan_time_liveliness = millis() + probe_interval;
    }
    Serial.flush();
}

void setup() {
    // Begin serial communicaton
    Serial.begin(SERIAL_BAUDRATE);
    // Wait for serial communication to be established
    while (!Serial) {delay(10);}

    fan = new BasicFan();
    solenoid = new BasicSolenoid();
    leds = new HorusLeds();
    motors = new HorusMotors();
    communication = new HorusCommunication(); // Unfinished
};

void loop() {
    // Set fan speed
    int fanSpeed = (communication->internalTemperture - 75)/(150.0 - 75)*100;
    fan->setPwmSpeed(fanSpeed);

    // Set solenoid lock
    solenoid->setState(communication->isLocked);

    // Set the automatic lights
    leds->setColors("west", communication->westColor[0], communication->westColor[1], communication->westColor[2]);
    leds->setColors("east", communication->eastColor[0], communication->eastColor[1], communication->eastColor[2]);
    leds->setColors("north", communication->northColor[0], communication->northColor[1], communication->northColor[2]);
    leds->setColors("south", communication->southColor[0], communication->southColor[1], communication->southColor[2]);
    leds->setColors("top", communication->topColor[0], communication->topColor[1], communication->topColor[2]);

    // Set the manual lights
    leds->setColors("west", communication->westColorManual[0], communication->westColorManual[1], communication->westColorManual[2], communication->westColorManual[3]);
    leds->setColors("east", communication->eastColorManual[0], communication->eastColorManual[1], communication->eastColorManual[2], communication->eastColorManual[3]);
    leds->setColors("north", communication->northColorManual[0], communication->northColorManual[1], communication->northColorManual[2], communication->northColorManual[3]);
    leds->setColors("south", communication->southColorManual[0], communication->southColorManual[1], communication->southColorManual[2], communication->southColorManual[3]);
    leds->setColors("top", communication->topColorManual[0], communication->topColorManual[1], communication->topColorManual[2], communication->topColorManual[3]);

    // Set the motors
    motors->customStep("west", communication->westMotor/100.0*MAX_STEP_NUM);
    communication->eastMotor != 0 ? motors->pillarAscend("east") : motors->pillarDescend("east");
    communication->northMotor != 0 ? motors->pillarAscend("north") : motors->pillarDescend("north");
    motors->customStep("south", communication->southMotor/100.0*MAX_STEP_NUM);
    communication->topMotor != 0 ? motors->pillarAscend("top") : motors->pillarDescend("top");

    // Check/send liveliness probe
    livelinessProbe();

};
