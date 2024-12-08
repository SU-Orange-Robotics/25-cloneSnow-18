 #include "vex.h"

#pragma once

const double intakePow = 100;
const double catPow = 90;

void stopAutoArming();

void intakeSpin(bool reversed = false);

void intakeSpinPow( double pow); // with false reversed decleared inside the function
void rollerSpinOnly(double pow);


void intakeStop();


void lockSpin(double pow);
void lockStake(double lockDeg, double unlockDeg);
void unlockStake(double deg);

void catapultLower();

void catapultRaise();

void catapultArm();

void catapultLaunch();

void catapultStop();

bool catInPosArmed();

void updateCatAccel(double time);

double getCatAccel();

void intakeSpinPow(double pow);