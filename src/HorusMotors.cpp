// Internal Import
#include "HorusMotors.h"

HorusMotors::HorusMotors() {
  westMotor = new BasicMotor(MOTOR1_1, MOTOR1_2, MOTOR1_3, MOTOR1_4, WEST_LIMIT_SWITCH_UPPER, WEST_LIMIT_SWITCH_LOWER);
  eastMotor = new BasicMotor(MOTOR2_1, MOTOR2_2, MOTOR2_3, MOTOR2_4, EAST_LIMIT_SWITCH_UPPER, EAST_LIMIT_SWITCH_LOWER);
  northMotor = new BasicMotor(MOTOR3_1, MOTOR3_2, MOTOR3_3, MOTOR3_4, NORTH_LIMIT_SWITCH_UPPER, NORTH_LIMIT_SWITCH_LOWER);
  southMotor = new BasicMotor(MOTOR4_1, MOTOR4_2, MOTOR4_3, MOTOR4_4, SOUTH_LIMIT_SWITCH_UPPER, SOUTH_LIMIT_SWITCH_LOWER);
  topMotor = new BasicMotor(MOTOR5_1, MOTOR5_2, MOTOR5_3, MOTOR5_4, TOP_LIMIT_SWITCH_UPPER, TOP_LIMIT_SWITCH_LOWER);
}

BasicMotor* HorusMotors::getSection(String section) {
  if (section == "west") {
    return westMotor;
  }
  else if (section == "east") {
    return eastMotor;
  }
  else if (section == "north") {
    return northMotor;
  }
  else if (section == "south") {
    return southMotor;
  }
  else if (section == "top") {
    return topMotor;
  }
  return nullptr;
}

void HorusMotors::pillarAscend(String section) {
  BasicMotor* selectedMotor = getSection(section);
  selectedMotor->ascend();
}

void HorusMotors::pillarDescend(String section) {
  BasicMotor* selectedMotor = getSection(section);
  selectedMotor->descend();
}

void HorusMotors::customStep(String section, int stepAmount) {
  BasicMotor* selectedMotor = getSection(section);
  selectedMotor->customStep(stepAmount);
}
