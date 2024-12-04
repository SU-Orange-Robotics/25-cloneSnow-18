#pragma once

#include "stack.h"

// ========== some autonomous routines ==========
void autonomous_competition(void);

// ========== retired autonomous routines ==========
void autonomous_skills_auto(void);

void green_autonomous(void);

void autonomous_old(void);

void autonomous(void);


void imuTurnTest(int pow, int targetDegree);

const int idealGoal = 4; // maximum stake the bot would interact based on the strategy

extern Stack completedStakes[idealGoal];
extern int completedStakesCount;

extern Stack currentStack;

void addRing(const std::string& ringDetails);  // called function stackRecord add in this function
void releaseStake();