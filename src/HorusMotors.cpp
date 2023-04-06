// Internal Import

bool BasicMotor::pillarsDecend() {
  return true;
}

void BasicMotor::westPillarPeak() {
  while (digitalRead(WEST_LIMIT_SWITCH_UPPER)) {
    stepperW->step(1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::westPillarTrough() {
  while (digitalRead(WEST_LIMIT_SWITCH_LOWER)) {
    stepperW->step(-1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::eastPillarPeak() {
  while (digitalRead(EAST_LIMIT_SWITCH_UPPER)) {
    stepperE->step(1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::eastPillarTrough() {
  while (digitalRead(EAST_LIMIT_SWITCH_LOWER)) {
    stepperE->step(-1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::northPillarPeak() {
  while (digitalRead(NORTH_LIMIT_SWITCH_UPPER)) {
    stepperN->step(1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::northPillarTrough() {
  while (digitalRead(NORTH_LIMIT_SWITCH_LOWER)) {
    stepperN->step(-1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::southPillarPeak() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_UPPER)) {
    stepperS->step(1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::southPillarTrough() {
  while (digitalRead(SOUTH_LIMIT_SWITCH_LOWER)) {
    stepperS->step(-1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::topPillarPeak() {
  while (digitalRead(TOP_LIMIT_SWITCH_UPPER)) {
    stepperT->step(1); // Make negative to go the counterclockwise
  }
}

void BasicMotor::topPillarTrough() {
  while (digitalRead(TOP_LIMIT_SWITCH_LOWER)) {
    stepperT->step(-1); // Make negative to go the counterclockwise
  }
}
