// Motor Controller Pins
#define MOTOR1_1 20
#define MOTOR1_2 21
#define MOTOR1_3 22
#define MOTOR1_4 23

#define MOTOR2_1 24
#define MOTOR2_2 25
#define MOTOR2_3 26
#define MOTOR2_4 27

#define MOTOR3_1 28
#define MOTOR3_2 29
#define MOTOR3_3 30
#define MOTOR3_4 31

#define MOTOR4_1 32
#define MOTOR4_2 33
#define MOTOR4_3 34
#define MOTOR4_4 35

#define MOTOR5_1 36
#define MOTOR5_2 37
#define MOTOR5_3 38
#define MOTOR5_4 39

//  How many steps per turn
#define stepsPerRevolution 200
#define BASE_MOTOR_SPEED 30

// Limit Switch Pins
#define WEST_LIMIT_SWITCH_UPPER 40
#define WEST_LIMIT_SWITCH_LOWER 41
#define EAST_LIMIT_SWITCH_UPPER 42
#define EAST_LIMIT_SWITCH_LOWER 43
#define NORTH_LIMIT_SWITCH_UPPER 44
#define NORTH_LIMIT_SWITCH_LOWER 45
#define SOUTH_LIMIT_SWITCH_UPPER 46
#define SOUTH_LIMIT_SWITCH_LOWER 47
#define TOP_LIMIT_SWITCH_UPPER 48
#define TOP_LIMIT_SWITCH_LOWER 49

// LEDs
#define LED_PIN 19 // The pin that the LED control header is in
#define NUM_LEDS 288

#define WEST_LED_START 0
#define WEST_LED_STOP 57
#define NORTH_LED_START 58
#define NORTH_LED_STOP 114
#define EAST_LED_START 115
#define EAST_LED_STOP 171
#define SOUTH_LED_START 172
#define SOUTH_LED_STOP 228
#define TOP_LED_START 229
#define TOP_LED_STOP 288

// Solenoid
#define SOLENOID_PIN 18

// Fan PWM Controller
#define FAN_CONTROL_PIN 13

// Serial
#define SERIAL_BAUDRATE 9600 

// Probe Interval
#define probe_interval 2250

// Packet Headers
#define TEMPERATURE 0
#define LOCK 1
#define HOME 2
#define KITCHEN_MOTION 3
#define LIVINGROOM_MOTION 4
#define BATHROOM_MOTION 5
#define BEDROOM_MOTION 6
#define CLOSET_MOTION 7
#define TOASTER 8
#define AIR_FRYER 9
#define RICE_COOKER 10
#define TV 11
#define SHOWER 12
#define COMPUTER 13
#define BED 14
#define POWER 15
#define WEST_PILLAR 16
#define WEST_LIGHT 17
#define WEST_COLOR 18
#define EAST_PILLAR 19
#define EAST_LIGHT 20
#define EAST_COLOR 21
#define NORTH_POSITION 22
#define NORTH_LIGHT 23
#define NORTH_COLOR 24
#define SOUTH_PILLAR 25
#define SOUTH_LIGHT 26
#define SOUTH_COLOR 27
#define TOP_PILLAR 28
#define TOP_LIGHT 29
#define TOP_COLOR 30
#define FAN 31
